import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, K;
    private static int[] DP = new int[100021];

    static class Pair {
        public int w, v;

        public Pair(int w, int v) {
            this.w = w;
            this.v = v;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Arrays.fill(DP, -1);

        List<Pair> pairs = new ArrayList<>();
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            pairs.add(new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        DP[0] = 0;
        for (int n = 0; n < N; n++) {
            for (int k = K; k >= pairs.get(n).w; k--) {
                if (DP[k - pairs.get(n).w] != Integer.MAX_VALUE) {
                    DP[k] = Math.max(DP[k] == Integer.MAX_VALUE ? 0 : DP[k], DP[k - pairs.get(n).w] + pairs.get(n).v);
                }
            }
        }

        int ret = 0;
        for (int k = K; k >= 1; k--) {
            if (DP[k] != Integer.MAX_VALUE) {
                ret = Math.max(ret, DP[k]);
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}