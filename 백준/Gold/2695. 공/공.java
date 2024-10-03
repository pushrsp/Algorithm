import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[][] DP = new int[51][1001];

    private static int go(int i, int j) {
        int ret = DP[1][j];
        if (DP[i][j] >= 0) {
            return DP[i][j];
        }
        for (int k = 1; k < j; k++) {
            ret = Math.min(ret, 1 + Math.max(go(i - 1, k - 1), go(i, j - k)));
        }
        return DP[i][j] = ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= 1000; i++) {
            DP[1][i] = i;
        }

        for (int i = 2; i <= 50; i++) {
            DP[i][1] = 1;
            for (int j = 2; j <= 1000; j++) {
                DP[i][j] = -1;
            }
        }

        N = Integer.parseInt(st.nextToken());
        for (int n = 1; n <= N; n++) {
            st = new StringTokenizer(br.readLine());
            bw.write(String.valueOf(go(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()))) + '\n');
        }

        br.close();
        bw.close();
    }
}