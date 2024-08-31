import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static boolean[] visited;
    private static List<int[]>[] G;

    private static int go(int n) {
        int ret = 0;
        for (int[] next : G[n]) {
            if (visited[next[0]]) {
                continue;
            }

            visited[next[0]] = true;
            ret += Math.min(next[1], go(next[0]));
        }

        return ret == 0 ? Integer.MAX_VALUE : ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        G = new List[N + 1];
        visited = new boolean[N + 1];

        for (int n = 0; n <= N; n++) {
            G[n] = new ArrayList<>();
        }

        int a, b, v;
        for (int n = 0; n < N - 1; n++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            G[a].add(new int[]{b, v});
            G[b].add(new int[]{a, v});
        }

        visited[1] = true;

        bw.write(String.valueOf(go(1)) + '\n');

        br.close();
        bw.close();
    }
}
