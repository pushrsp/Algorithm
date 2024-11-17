import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static long K;
    private static long[][] DP = new long[101][101];

    private static void go(int a, int z) {

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        for (int i = 1; i <= 100; i++) {
            DP[i][0] = DP[0][i] = 1;
        }

        for (int n = 1; n <= N; n++) {
            for (int m = 1; m <= M; m++) {
                DP[n][m] = DP[n - 1][m] + DP[n][m - 1];
                if (DP[n][m] > 1000000000) {
                    DP[n][m] = 1000000000;
                }
            }
        }

        if (DP[N][M] < K) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            int aCount = N;
            int zCount = M;

            for (int i = 0; i < N + M; i++) {
                if (aCount == 0) {
                    bw.write('z');
                    zCount--;
                    continue;
                }

                if (zCount == 0) {
                    bw.write('a');
                    aCount--;
                    continue;
                }

                long count = DP[aCount - 1][zCount];
                if (K <= count) {
                    bw.write('a');
                    aCount--;
                } else {
                    K -= count;
                    bw.write('z');
                    zCount--;
                }
            }
        }
        bw.write('\n');

        br.close();
        bw.close();
    }
}