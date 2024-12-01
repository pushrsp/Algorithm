import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[] DP = new int[10001];
    private static List<Integer> W = new ArrayList<>();

    private static int go(int remain) {
        if (remain == 0) {
            return 0;
        }

        if (DP[remain] != -1) {
            return DP[remain];
        }

        DP[remain] = 9999999;
        for (int l = 0; l < M + 1; l++) {
            for (int r = 0; r < M + 1; r++) {
                if (l == r) {
                    continue;
                }

                int sum = W.get(l) + W.get(r);
                if (sum > remain) {
                    continue;
                }

                DP[remain] = Math.min(DP[remain], go(remain - sum) + 1);
            }
        }
        return DP[remain];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Arrays.fill(DP, -1);

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        W.add(0);

        for (int m = 0; m < M; m++) {
            W.add(Integer.parseInt(st.nextToken()));
        }

        int ret = go(N);
        if (ret == 9999999) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(ret) + '\n');
        }

        br.close();
        bw.close();
    }
}