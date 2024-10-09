import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, Q, B, R;
    private static int[] C;
    private static long[] A;
    private static final List<List<Integer>> G = new ArrayList<>();

    private static Pair go(int curr, int parent) {
        long r = 0;
        long b = 0;
        for (Integer node : G.get(curr)) {
            if (node == parent) {
                continue;
            }
            Pair p = go(node, curr);
            A[curr] += r * p.s + b * p.f;
            r += p.f;
            b += p.s;
        }

        if (C[curr] == 1) {
            A[curr] += r * (B - b) + b * (R - r - 1);
        } else {
            A[curr] += r * (B - b - 1) + b * (R - r);
        }

        if (C[curr] == 1) {
            r++;
        } else {
            b++;
        }

        final Pair ret = new Pair();
        ret.f = r;
        ret.s = b;
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = new int[N + 1];
        A = new long[N + 1];

        for (int n = 0; n <= N; n++) {
            G.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            C[n] = Integer.parseInt(st.nextToken());
            if (C[n] == 1) {
                R++;
            } else {
                B++;
            }
        }

        int u, v;
        for (int n = 0; n < N - 1; n++) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            G.get(u).add(v);
            G.get(v).add(u);
        }

        st = new StringTokenizer(br.readLine());
        Q = Integer.parseInt(st.nextToken());

        go(1, -1);

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            int node = Integer.parseInt(st.nextToken());
            bw.write(String.valueOf(A[node]) + '\n');
        }

        br.close();
        bw.close();
    }

    static class Pair {
        long f, s;
    }
}