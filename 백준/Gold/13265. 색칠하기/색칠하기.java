import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int T = Integer.parseInt(br.readLine().trim());
        
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            
            List<List<Integer>> graph = new ArrayList<>();
            for (int i = 0; i <= N; i++) {
                graph.add(new ArrayList<>());
            }
            
            boolean selfLoop = false;
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                
                if (x == y) {
                    selfLoop = true;
                    continue;
                }
                graph.get(x).add(y);
                graph.get(y).add(x);
            }
            
            if (selfLoop) {
                sb.append("impossible\n");
                continue;
            }
            
            int[] color = new int[N + 1];
            boolean possible = true;
            
            // 모든 컴포넌트 검사 (비연결 그래프 대응)
            for (int start = 1; start <= N && possible; start++) {
                if (color[start] != 0) continue;
                
                Queue<Integer> queue = new LinkedList<>();
                queue.offer(start);
                color[start] = 1;
                
                while (!queue.isEmpty() && possible) {
                    int cur = queue.poll();
                    for (int next : graph.get(cur)) {
                        if (color[next] == 0) {
                            color[next] = (color[cur] == 1) ? 2 : 1;
                            queue.offer(next);
                        } else if (color[next] == color[cur]) {
                            possible = false;
                            break;
                        }
                    }
                }
            }
            
            sb.append(possible ? "possible\n" : "impossible\n");
        }
        
        System.out.print(sb);
    }
}