import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int T, N, M;
    private static int[] C = new int[21];
    private static int[][] DP = new int[21][10001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            for (int i = 1; i <= N; i++) {
                Arrays.fill(DP[i], 0);
            }
            Arrays.fill(C, 0);

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                C[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());

            for (int i = 1; i <= N; i++) {
                DP[i][0] = 1;
                for (int j = 1; j <= M; j++) {
                    if (C[i] <= j) {
                        DP[i][j] += DP[i - 1][j] + DP[i][j - C[i]];
                    } else {
                        DP[i][j] = DP[i - 1][j];
                    }
                }
            }

            bw.write(String.valueOf(DP[N][M]) + '\n');
        }

        br.close();
        bw.close();
    }
}