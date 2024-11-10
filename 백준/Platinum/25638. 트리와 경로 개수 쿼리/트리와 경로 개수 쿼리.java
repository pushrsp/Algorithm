import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, R, B, Q;
    private static int[] C;
    private static List<List<Integer>> G = new ArrayList<>();
    private static List<List<Integer>> T = new ArrayList<>();
    private static long[][] DP = new long[100001][2];

    private static void go(int curr, int prev) {
        for (int next : G.get(curr)) {
            if (next == prev) {
                continue;
            }

            T.get(curr).add(next);
            go(next, curr);

            DP[curr][0] += DP[next][0];
            DP[curr][1] += DP[next][1];
        }

        if (C[curr] == 1) {
            DP[curr][0] += 1;
        } else {
            DP[curr][1] += 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            C[n] = Integer.parseInt(st.nextToken());

            if (C[n] == 1) {
                R += 1;
            } else {
                B += 1;
            }
            G.add(new ArrayList<>());
            T.add(new ArrayList<>());
        }
        G.add(new ArrayList<>());
        T.add(new ArrayList<>());

        int u, v;
        for (int n = 0; n < N - 1; n++) {
            st = new StringTokenizer(br.readLine());

            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            G.get(u).add(v);
            G.get(v).add(u);
        }

        Q = Integer.parseInt(br.readLine());

        go(1, -1);

        long[] result = new long[N + 1];
        for (int n = 1; n <= N; n++) {
            long notSubTreeRed = R - DP[n][0];
            long notSubTreeBlue = B - DP[n][1];

            for (int child : T.get(n)) {
                result[n] += DP[child][0] * notSubTreeBlue;
                result[n] += DP[child][1] * notSubTreeRed;
                notSubTreeRed += DP[child][0];
                notSubTreeBlue += DP[child][1];
            }
        }

        int node;
        for (int q = 0; q < Q; q++) {
            node = Integer.parseInt(br.readLine());
            bw.write(String.valueOf(result[node]) + '\n');
        }

        br.close();
        bw.close();
    }
}