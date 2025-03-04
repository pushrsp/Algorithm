import java.util.*;

public class Solution {
    public int[] solution(int[] nodes, int[][] edges) {
        int n = nodes.length;
        // 노드 값이 연속적이지 않을 수 있으므로, 각 노드 값을 인덱스로 매핑합니다.
        Map<Integer, Integer> nodeToIndex = new HashMap<>();
        for (int i = 0; i < n; i++) {
            nodeToIndex.put(nodes[i], i);
        }
        
        // 인접 리스트 형태로 그래프를 구성합니다.
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        // 각 노드의 degree (무방향 간선의 개수) 저장
        int[] degree = new int[n];
        for (int[] edge : edges) {
            int u = nodeToIndex.get(edge[0]);
            int v = nodeToIndex.get(edge[1]);
            graph[u].add(v);
            graph[v].add(u);
            degree[u]++;
            degree[v]++;
        }
        
        boolean[] visited = new boolean[n];
        int normalTreeCount = 0;
        int reverseTreeCount = 0;
        
        // 포레스트의 각 연결 요소(트리)에 대해 DFS 수행
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                List<Integer> compNodes = new ArrayList<>();
                Stack<Integer> stack = new Stack<>();
                stack.push(i);
                visited[i] = true;
                
                while (!stack.isEmpty()) {
                    int cur = stack.pop();
                    compNodes.add(cur);
                    for (int neighbor : graph[cur]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            stack.push(neighbor);
                        }
                    }
                }
                
                int compSize = compNodes.size();
                int sameCount = 0; // 노드 번호의 홀짝과 degree의 홀짝이 같은 경우
                int diffCount = 0; // 노드 번호의 홀짝과 degree의 홀짝이 다른 경우
                
                // 각 노드의 홀짝 상태를 확인합니다.
                // 노드 번호 홀짝: 홀수면 1, 짝수면 0 (0은 짝수)
                // degree의 홀짝: degree % 2 (짝수면 0, 홀수면 1)
                for (int idx : compNodes) {
                    int nodeVal = nodes[idx];
                    int x = (nodeVal & 1);        // 노드 번호의 홀짝 (홀수:1, 짝수:0)
                    int y = (degree[idx] & 1);      // degree의 홀짝 (홀수:1, 짝수:0)
                    if (x == y) {
                        sameCount++;
                    } else {
                        diffCount++;
                    }
                }
                
                // 노말(홀짝) 트리 조건:
                //   - 루트: X == Y, 비루트: X != Y → 전체에서 단 1개만 X == Y인 노드가 있으면 가능
                if (sameCount == 1 && diffCount == compSize - 1) {
                    normalTreeCount++;
                }
                // 역홀짝 트리 조건:
                //   - 루트: X != Y, 비루트: X == Y → 전체에서 단 1개만 X != Y인 노드가 있으면 가능
                if (diffCount == 1 && sameCount == compSize - 1) {
                    reverseTreeCount++;
                }
            }
        }
        
        return new int[] { normalTreeCount, reverseTreeCount };
    }
}
