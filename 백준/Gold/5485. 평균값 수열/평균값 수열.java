import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static long[] M = new long[5_000_003];
    private static long[] dp = new long[5_000_003];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            M[i] = Long.parseLong(br.readLine());
            M[i] *= 2;
        }

        dp[2] = M[1];
        for (int i = 3; i <= N + 1; i++) {
            dp[i] = M[i - 1] - dp[i - 1];
        }

        long min = Long.MIN_VALUE;
        long max = Long.MAX_VALUE;
        for (int i = 2; i <= N + 1; i++) {
            if (i % 2 == 0) {
                max = Math.min(max, (dp[i] - dp[i - 1]) / 2);
            } else {
                min = Math.max(min, (dp[i - 1] - dp[i]) / 2);
            }
        }

        if (max < min) {
            bw.write("0\n");
        } else {
            bw.write(String.valueOf((max - min) + 1) + '\n');
        }

        br.close();
        bw.close();
    }
}