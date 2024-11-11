import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int K;
    private static boolean[] PRIME = new boolean[1000001];

    private static int go(int k) {
        if (PRIME[k]) {
            return 1;
        }

        int ret = Integer.MAX_VALUE;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                int left = go(i) + 1;
                int right = go(k / i) + 1;
                ret = Math.min(ret, Math.max(left, right));
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());
        for (int k = 2; k <= K; k++) {
            PRIME[k] = true;
        }

        for (int i = 2; i * i <= K; i++) {
            if (PRIME[i]) {
                for (int j = i * i; j <= K; j += i) {
                    PRIME[j] = false;
                }
            }
        }

        bw.write(String.valueOf(go(K) - 1) + '\n');

        br.close();
        bw.close();
    }
}