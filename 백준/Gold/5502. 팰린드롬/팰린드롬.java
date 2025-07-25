import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int[][] DP = new int[5_001][5_001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        String s1 = ' ' + br.readLine();

        StringBuilder sb = new StringBuilder(s1);
        String s2 = ' ' + sb.reverse().toString();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                DP[i][j] = Math.max(DP[i - 1][j], DP[i][j - 1]);
                if (s1.charAt(i) == s2.charAt(j)) {
                    DP[i][j] = Math.max(DP[i - 1][j - 1] + 1, DP[i][j]);
                }
            }
        }

        bw.write(String.valueOf(n - DP[n][n]) + '\n');

        br.close();
        bw.close();
    }
}