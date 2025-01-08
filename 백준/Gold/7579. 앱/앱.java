import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[] A;
    private static int[] C;
    private static int[][] DP = new int[101][10001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        A = new int[N + 1];
        C = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            A[n] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            C[n] = Integer.parseInt(st.nextToken());
        }

        int ret = Integer.MAX_VALUE;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= 10000; j++) {
                if (C[i] <= j) {
                    DP[i][j] = Math.max(DP[i - 1][j], DP[i - 1][j - C[i]] + A[i]);
                } else {
                    DP[i][j] = DP[i - 1][j];
                }

                if (DP[i][j] >= M) {
                    ret = Math.min(ret, j);
                }
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}