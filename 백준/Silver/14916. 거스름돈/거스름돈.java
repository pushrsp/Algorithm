import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] DP = new int[100001];

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

        N = Integer.parseInt(st.nextToken());

        Arrays.fill(DP, 999999999);

        DP[0] = 0;
        for (int i = 0; i < N; i++) {
            if (i + 5 <= N) {
                DP[i + 5] = Math.min(DP[i + 5], DP[i] + 1);
            }

            if (i + 2 <= N) {
                DP[i + 2] = Math.min(DP[i + 2], DP[i] + 1);
            }
        }

        int ret = DP[N];
        if (ret != 999999999) {
            bw.write(String.valueOf(DP[N]) + '\n');
        } else {
            bw.write(String.valueOf(-1) + '\n');
        }

        br.close();
        bw.close();
    }
}