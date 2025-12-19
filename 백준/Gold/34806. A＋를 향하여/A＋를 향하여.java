import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, T, W;
    private static List<Test> tests = new ArrayList<>();

    private static long go(int x) {
        int remainTime = T - x;
        if (remainTime < 0) return 0;

        // dp[j] = 시간 j 이내로 얻을 수 있는 최대 점수
        long[] dp = new long[remainTime + 1];

        for (int i = 1; i <= N; i++) {
            int time = Math.max(0, tests.get(i).t - x);
            int score = tests.get(i).w;

            // 역순으로 갱신 (0/1 배낭)
            for (int j = remainTime; j >= time; j--) {
                dp[j] = Math.max(dp[j], dp[j - time] + score);
            }
        }

        return dp[remainTime];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        tests.add(new Test(0, 0));
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            tests.add(new Test(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        int left = 0, right = T * 2;
        int ret = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (go(mid) >= W) {
                right = mid - 1;
                ret = mid;
            } else {
                left = mid + 1;
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    static class Test {
        int t, w;

        public Test(int t, int w) {
            this.t = t;
            this.w = w;
        }
    }
}