import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int[] A = new int[1001];
    private static int[] DP = new int[1001];
    private static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int n = 0; n < N; n++) {
            A[n] = Integer.parseInt(st.nextToken());
        }

        int ret = 1;
        for (int i = 0; i < N; i++) {
            DP[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (A[i] > A[j]) {
                    DP[i] = Math.max(DP[i], DP[j] + 1);
                }
            }
            ret = Math.max(DP[i], ret);
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}