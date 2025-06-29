import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[][] DP;
    private static int MAX = 987654321;
    private static Set<Integer> HOLIDAY = new HashSet<>();

    private static boolean hasCoupon(int coupon) {
        return coupon >= 3;
    }

    private static int go(int day, int coupon) {
        if (day > N) {
            return 0;
        }

        if (DP[day][coupon] != MAX) {
            return DP[day][coupon];
        }

        if (HOLIDAY.contains(day)) {
            return DP[day][coupon] = Math.min(DP[day][coupon], go(day + 1, coupon));
        } else {
            DP[day][coupon] = Math.min(DP[day][coupon], go(day + 1, coupon) + 10_000);
            DP[day][coupon] = Math.min(DP[day][coupon], go(day + 3, coupon + 1) + 25_000);
            DP[day][coupon] = Math.min(DP[day][coupon], go(day + 5, coupon + 2) + 37_000);
            if (hasCoupon(coupon)) {
                DP[day][coupon] = Math.min(DP[day][coupon], go(day + 1, coupon - 3));
            }

            return DP[day][coupon];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        DP = new int[N + 1][N + 1];
        for (int i = 0; i < N + 1; i++) {
            for (int k = 0; k < N + 1; k++) {
                DP[i][k] = MAX;
                DP[i][k] = MAX;
            }
        }
        M = Integer.parseInt(st.nextToken());

        if (M > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                HOLIDAY.add(Integer.parseInt(st.nextToken()));
            }
        }

        bw.write(String.valueOf(go(1, 0)) + '\n');

        br.close();
        bw.close();
    }
}