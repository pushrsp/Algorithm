import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int a, b, d, N;
    private static int[] DP = new int[1_000_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < a; i++) {
            DP[i] = 1;
        }

        for (int i = a; i <= N; i++) {
            DP[i] = (DP[i - 1] + DP[i - a]) % 1_000;
            if (i >= b) {
                DP[i] = (DP[i] - DP[i - b] + 1_000) % 1_000;
            }
        }

        int ret = DP[N];
        if (N >= d) {
            ret = (ret + 1_000 - DP[N - d]) % 1_000;
        }

        bw.write(String.valueOf(ret));

        br.close();
        bw.close();
    }
}