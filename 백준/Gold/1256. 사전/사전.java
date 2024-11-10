import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static long K;
    private static long[][] DP = new long[501][501];

    private static long comb(int s, int r) {
        if (s == r || r <= 0) {
            return 1;
        }
        if (DP[s][r] != -1) {
            return DP[s][r];
        }
        long v1 = comb(s - 1, r - 1);
        long v2 = comb(s - 1, r);
        if (v1 + v2 > 1_000_000_000L) {
            return DP[s][r] = 0x3f3f3f3f3f3f3f3fL;
        }
        return DP[s][r] = v1 + v2;
    }

    private static void go(int n, int m, long k, BufferedWriter bw) throws IOException {
        long total = comb(n + m - 1, n - 1);
        if (n > 0 && k <= total) {
            bw.write('a');
            go(n - 1, m, k, bw);
        } else if (m > 0) {
            bw.write('z');
            go(n, m - 1, k - total, bw);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        for (int i = 0; i < 501; i++) {
            Arrays.fill(DP[i], -1);
        }

        if (comb(N + M, N) < K) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            go(N, M, K, bw);
            bw.write('\n');
        }

        br.close();
        bw.close();
    }
}