import java.io.*;
import java.util.*;

public class Main {

    private static final long MOD = 1000000007;
    private static int N, Q, X, Y;
    private static int[] house;
    private static List<Integer>[] Adj;

    private static long concat(long a, long b) {
        long ret = a;
        for (long i = b; i > 0; i /= 10)
            ret = (ret * 10) % MOD;

        ret += b;
        ret %= MOD;

        return ret;
    }

    private static long bfs() {
        Queue<Integer> q = new LinkedList<>();
        long[] visited = new long[N + 1];
        Arrays.fill(visited, -1);

        q.add(X);
        visited[X] = house[X];

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int next : Adj[cur]) {
                if (visited[next] != -1)
                    continue;

                visited[next] = concat(visited[cur], house[next]);
                q.add(next);
            }
        }

        return visited[Y];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        Adj = new List[N + 1];

        st = new StringTokenizer(br.readLine());
        house = new int[N + 1];

        Adj[0] = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            house[i] = Integer.parseInt(st.nextToken());
            Adj[i] = new ArrayList<>();
        }

        int a, b;
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            Adj[a].add(b);
            Adj[b].add(a);
        }

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());

            X = Integer.parseInt(st.nextToken());
            Y = Integer.parseInt(st.nextToken());

            bw.write(bfs() + "\n");
        }

        bw.close();
        br.close();
    }
}
