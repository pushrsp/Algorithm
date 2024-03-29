import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static final int INF = -200000102;
    private static int N;
    private static int[] A = new int[200005];
    private static int[] sum = new int[200005];
    private static int[][] dp = new int[200005][2];

    private static int go(int n, int pressed) {
        if(n > N) {
            return 0;
        }

        if(dp[n][pressed] != INF) {
            return dp[n][pressed];
        }

        //스위치를 누를 경우
        dp[n][pressed] = Math.max(dp[n][pressed], go(n + 3, 1) + ((sum[Math.min(N, n + 2)] - sum[n - 1]) * 2));

        //스위치를 누르지 않을 경우
        dp[n][pressed] = Math.max(dp[n][pressed], go(n + 1, 0) + A[n]);

        return dp[n][pressed];
    }

    public static void main(String[] args) throws IOException, NoSuchMethodException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        bw.write(String.valueOf(go(1, 0)) + '\n');

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        dp[0][0] = INF;
        dp[0][1] = INF;

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            A[n] = Integer.parseInt(st.nextToken());
            dp[n][0] = INF;
            dp[n][1] = INF;
            sum[n] = sum[n - 1] + A[n];
        }

        for (int n = N + 1; n <= N + 3; n++) {
            sum[n] = sum[N];
        }
    }
}
