import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static long[] DP;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        DP = new long[31];

        DP[0] = 1;
        DP[2] = 3;

        for (int i = 4; i <= n; i += 2) {
            DP[i] = DP[i - 2] * DP[2];

            for (int j = i - 4; j >= 0; j -= 2)
                DP[i] += DP[j] * 2;
        }

        bw.write(DP[n] + "\n");

        bw.close();
        br.close();
    }
}
