import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    private static int K, V, E;
    private static boolean[] VISITED = new boolean[20001];
    private static int[] MARK = new int[20001];
    private static List<Integer>[] G = new List[20001];

    private static boolean bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        VISITED[start] = true;
        MARK[start] = 1;

        while (!q.isEmpty()) {
            int curr = q.poll();
            for (Integer next : G[curr]) {
                if (!VISITED[next]) {
                    VISITED[next] = true;
                    MARK[next] = (MARK[curr] + 1) % 2;
                    q.add(next);
                } else {
                    if (MARK[curr] == MARK[next]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());

        while (K-- > 0) {
            st = new StringTokenizer(br.readLine());

            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());

            Arrays.fill(VISITED, false);
            Arrays.fill(MARK, 0);

            for (int i = 0; i <= V; i++) {
                G[i] = new ArrayList<>();
            }

            int u, v;
            for (int i = 0; i < E; i++) {
                st = new StringTokenizer(br.readLine());

                u = Integer.parseInt(st.nextToken());
                v = Integer.parseInt(st.nextToken());

                G[u].add(v);
                G[v].add(u);
            }

            boolean ret = true;
            for (int i = 1; i <= V; i++) {
                if (!VISITED[i]) {
                    if (!bfs(i)) {
                        ret = false;
                    }
                }
            }

            if (ret) {
                bw.write("YES\n");
            } else {
                bw.write("NO\n");
            }
        }

        br.close();
        bw.close();
    }
} 