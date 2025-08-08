import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int T, N, M;
    private static int[] A = new int[21];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());


            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                A[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());

            M = Integer.parseInt(st.nextToken());

            long[][] dp = new long[21][10_001];
            for (int m = A[1]; m <= M; m += A[1]) {
                dp[1][m] = 1;
            }

            for (int n = 2; n <= N; n++) {
                dp[n][A[n]] = 1;
                for (int m = 1; m <= M; m++) {
                    dp[n][m] += dp[n - 1][m];
                    if (m > A[n]) {
                        dp[n][m] += dp[n][m - A[n]];
                    }
                }
            }

            bw.write(String.valueOf(dp[N][M]) + '\n');
            Arrays.fill(A, 0);
        }

        br.close();
        bw.close();
    }
}