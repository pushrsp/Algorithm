import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static double P, Q;
    private static long[][] comb = new long[21][21];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 이항계수 미리 계산
        for (int i = 0; i <= 20; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    comb[i][j] = 1;
                } else {
                    comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                }
            }
        }

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        P = Double.parseDouble(st.nextToken());
        Q = Double.parseDouble(st.nextToken());

        double maxExpected = 0.0;
        for (int k = 0; k <= N; k++) {
            double expected = 0.0;
            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= N; j++) {
                    int total = i + j;

                    if (total > N) {
                        continue;
                    }

                    double prob_i = comb[k][i] * Math.pow(P, i) * Math.pow(1 - P, k - i);
                    double prob_j = comb[N][j] * Math.pow(Q, j) * Math.pow(1 - Q, N - j);

                    expected += prob_i * prob_j * total;
                }
            }

            maxExpected = Math.max(maxExpected, expected);
        }

        bw.write(String.valueOf(maxExpected));
        bw.newLine();
        bw.close();
    }
}