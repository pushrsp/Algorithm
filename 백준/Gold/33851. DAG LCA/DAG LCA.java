import java.io.*;
import java.util.*;

public class Main {
    static final int INF = Integer.MAX_VALUE;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        
        List<List<Integer>> graph = new ArrayList<>();
        List<List<Integer>> reverseGraph = new ArrayList<>();
        int[] indegree = new int[n + 1];
        
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
            reverseGraph.add(new ArrayList<>());
        }
        
        // 간선 입력 및 진입차수 계산
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            reverseGraph.get(v).add(u);
            indegree[v]++;
        }
        
        // 위상정렬 순서 구하기
        List<Integer> topoOrder = topologicalSort(graph, indegree, n);
        
        // 모든 정점에서의 최단거리 계산 (위상정렬 + DP)
        int[][] dist = new int[n + 1][n + 1];
        
        // 초기화
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }
        
        // 각 시작점에 대해 위상정렬 순서로 DP
        for (int start = 1; start <= n; start++) {
            boolean[] visited = new boolean[n + 1];
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(start);
            visited[start] = true;
            
            while (!queue.isEmpty()) {
                int current = queue.poll();
                
                for (int next : graph.get(current)) {
                    if (dist[start][next] > dist[start][current] + 1) {
                        dist[start][next] = dist[start][current] + 1;
                        if (!visited[next]) {
                            queue.offer(next);
                            visited[next] = true;
                        }
                    }
                }
            }
        }
        
        // 쿼리 전처리: 각 (u,v) 쌍에 대해 미리 계산
        Map<String, Integer> queryCache = new HashMap<>();
        
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            
            String key = u + "," + v;
            Integer cached = queryCache.get(key);
            
            if (cached != null) {
                sb.append(cached).append('\n');
                continue;
            }
            
            int answer = INF;
            boolean found = false;
            
            // 모든 정점 w에 대해 확인
            for (int w = 1; w <= n; w++) {
                if (dist[w][u] != INF && dist[w][v] != INF) {
                    found = true;
                    int maxDist = Math.max(dist[w][u], dist[w][v]);
                    answer = Math.min(answer, maxDist);
                }
            }
            
            int result = found ? answer : -1;
            queryCache.put(key, result);
            sb.append(result).append('\n');
        }
        
        System.out.print(sb.toString());
    }
    
    static List<Integer> topologicalSort(List<List<Integer>> graph, int[] indegree, int n) {
        List<Integer> result = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        int[] tempIndegree = indegree.clone();
        
        for (int i = 1; i <= n; i++) {
            if (tempIndegree[i] == 0) {
                queue.offer(i);
            }
        }
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            result.add(current);
            
            for (int next : graph.get(current)) {
                tempIndegree[next]--;
                if (tempIndegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }
        
        return result;
    }
}

// 더 최적화된 버전: 비트셋 활용
class BitsetOptimizedSolution {
    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
        }
        
        // 각 정점에서 도달 가능한 정점들을 비트셋으로 표현
        BitSet[] reachable = new BitSet[n + 1];
        int[][] dist = new int[n + 1][n + 1];
        
        for (int i = 1; i <= n; i++) {
            reachable[i] = new BitSet(n + 1);
            Arrays.fill(dist[i], -1);
            
            // BFS로 도달가능성과 거리 계산
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(i);
            dist[i][i] = 0;
            reachable[i].set(i);
            
            while (!queue.isEmpty()) {
                int current = queue.poll();
                
                for (int next : graph.get(current)) {
                    if (!reachable[i].get(next)) {
                        reachable[i].set(next);
                        dist[i][next] = dist[i][current] + 1;
                        queue.offer(next);
                    }
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            
            int answer = Integer.MAX_VALUE;
            boolean found = false;
            
            for (int w = 1; w <= n; w++) {
                if (reachable[w].get(u) && reachable[w].get(v)) {
                    found = true;
                    int maxDist = Math.max(dist[w][u], dist[w][v]);
                    answer = Math.min(answer, maxDist);
                }
            }
            
            sb.append(found ? answer : -1).append('\n');
        }
        
        System.out.print(sb.toString());
    }
}

// 메모리 최적화된 버전
class MemoryOptimizedSolution {
    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
        }
        
        StringBuilder sb = new StringBuilder();
        
        // 각 쿼리마다 필요한 거리만 계산
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            
            int answer = Integer.MAX_VALUE;
            boolean found = false;
            
            // 각 정점 w에서 u, v로의 거리를 BFS로 계산
            for (int w = 1; w <= n; w++) {
                int[] dist = new int[n + 1];
                Arrays.fill(dist, -1);
                
                Queue<Integer> queue = new LinkedList<>();
                queue.offer(w);
                dist[w] = 0;
                
                while (!queue.isEmpty()) {
                    int current = queue.poll();
                    
                    for (int next : graph.get(current)) {
                        if (dist[next] == -1) {
                            dist[next] = dist[current] + 1;
                            queue.offer(next);
                        }
                    }
                }
                
                if (dist[u] != -1 && dist[v] != -1) {
                    found = true;
                    int maxDist = Math.max(dist[u], dist[v]);
                    answer = Math.min(answer, maxDist);
                }
            }
            
            sb.append(found ? answer : -1).append('\n');
        }
        
        System.out.print(sb.toString());
    }
}