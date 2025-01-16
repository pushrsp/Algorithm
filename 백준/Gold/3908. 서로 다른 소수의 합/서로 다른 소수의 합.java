import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int T, N, K;
    private static boolean[] P = new boolean[1121];
    private static int[][] DP = new int[2001][15];
    private static List<Integer> primes = new ArrayList<>();

    private static int lowerBound(int target, List<Integer> list) {
        if (list.isEmpty()) {
            return 0;
        }

        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        P[0] = P[1] = true;
        for (int i = 2; i <= 1120; i++) {
            if (!P[i]) {
                for (int j = i * i; j <= 1120; j += i) {
                    P[j] = true;
                }
            }
        }

        for (int i = 2; i < 1120; i++) {
            if (!P[i]) {
                primes.add(i);
            }
        }

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            for (int i = 0; i < 2001; i++) {
                Arrays.fill(DP[i], 0);
            }

            for (int i = 0; i < primes.size(); i++) {
                if (primes.get(i) > N) {
                    break;
                }

                for (int j = N; j > 1; j--) {
                    if (j - primes.get(i) < 0) {
                        continue;
                    }
                    if (j == primes.get(i)) {
                        DP[j][1] = 1;
                        continue;
                    }

                    for (int k = 2; k <= K; k++) {
                        DP[j][k] += DP[j - primes.get(i)][k - 1];
                    }
                }
            }

            bw.write(String.valueOf(DP[N][K]) + '\n');
        }

        br.close();
        bw.close();
    }
}