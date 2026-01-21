import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, C;
    private static int[][][] dp = new int[11][21][1 << 13];
    private static int[] J;

    private static int go(int m, int visited, int c) {
        if (m == M) {
            return 0;
        }

        int ret = dp[m][c][visited];
        if (ret != -1) {
            return ret;
        }

        ret = 0;
        for (int i = 0; i < N; i++) {
            if ((visited & (1 << i)) != 0) {
                continue;
            } else {
                if (c + J[i] < C) {
                    ret = Math.max(ret, go(m, visited | (1 << i), c + J[i]) + 1);
                } else if (c + J[i] == C) {
                    ret = Math.max(ret, go(m + 1, visited | (1 << i), 0) + 1);
                } else {
                    ret = Math.max(ret, go(m + 1, visited, 0));
                }
            }
        }

        return dp[m][c][visited] = ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        J = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            J[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= C; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        bw.write(String.valueOf(go(0, 0, 0)) + '\n');

        br.close();
        bw.close();
    }
}