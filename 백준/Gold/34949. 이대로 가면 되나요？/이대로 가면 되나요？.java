import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] A;
    private static int[] dp;
    private static int[] state;
    private static final int UNVISITED = 0;
    private static final int VISITING = 1;
    private static final int DONE = 2;

    private static int solve(int curr) {
        if (curr == N) {
            return 0;
        }

        if (state[curr] == DONE) {
            return dp[curr];
        }

        if (state[curr] == VISITING) {
            return -1;
        }

        state[curr] = VISITING;

        int next = A[curr];
        int result = solve(next);

        if (result == -1) {
            dp[curr] = -1;
        } else {
            dp[curr] = result + 1;
        }

        state[curr] = DONE;

        return dp[curr];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        A = new int[N + 1];
        dp = new int[N + 1];
        state = new int[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            if (state[i] == UNVISITED) {
                solve(i);
            }
        }

        for (int i = 1; i <= N; i++) {
            bw.write(String.valueOf(dp[i]) + '\n');
        }

        br.close();
        bw.close();
    }
}