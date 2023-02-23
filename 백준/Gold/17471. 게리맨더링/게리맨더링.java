import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final int INF = 987654321;
    private static final List<Integer> T1 = new ArrayList<>();
    private static final List<Integer> T2 = new ArrayList<>();
    private static int N, A;
    private static int[] gu;
    private static int[] visited;
    private static boolean[] v1, v2;
    private static List<Integer>[] adj;

    private static void go(int cur, int color, boolean[] check) {
        check[cur] = true;

        for (Integer next : adj[cur]) {
            if (visited[next] != color)
                continue;
            if (check[next])
                continue;

            go(next, color, check);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        gu = new int[N + 1];
        adj = new ArrayList[N + 1];
        visited = new int[N + 1];
        v1 = new boolean[N + 1];
        v2 = new boolean[N + 1];
        A = (1 << (N + 1)) - 1;

        for (int i = 0; i <= N; i++)
            adj[i] = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            gu[i] = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int g = Integer.parseInt(st.nextToken());

            for (int j = 0; j < g; j++)
                adj[i].add(Integer.parseInt(st.nextToken()));
        }

        int ret = INF;
        for (int i = 3; i <= A; i++) {
            for (int j = 1; j <= N; j++) {
                if ((i & (1 << j)) != 0)
                    T1.add(j);
                else
                    T2.add(j);
            }

            if (T1.isEmpty() || T2.isEmpty())
                continue;

            for (Integer candidate : T1)
                visited[candidate] = 0;
            for (Integer candidate : T2)
                visited[candidate] = 1;


            go(T1.get(0), 0, v1);
            go(T2.get(0), 1, v2);

            boolean valid = true;

            for (Integer cand : T1) {
                if (!v1[cand])
                    valid = false;
            }

            for (Integer cand : T2) {
                if (!v2[cand])
                    valid = false;
            }

            if (valid) {
                int s1 = 0, s2 = 0;

                for (Integer cand : T1)
                    s1 += gu[cand];
                for (Integer cand : T2)
                    s2 += gu[cand];

                ret = Math.min(ret, Math.abs(s1 - s2));
            }
            Arrays.fill(visited, -1);
            Arrays.fill(v1, false);
            Arrays.fill(v2, false);
            T1.clear();
            T2.clear();
        }

        if (ret == INF)
            bw.write(-1 + "\n");
        else
            bw.write(ret + "\n");

        bw.close();
        br.close();
    }
}
