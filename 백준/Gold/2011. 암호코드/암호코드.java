import java.awt.*;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    private static final int MOD = 1000000;
    private static int[] dp = new int[5001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String s = st.nextToken();

        dp[0] = 1;
        for(int i = 1; i <= s.length(); i++) {
            if('1' <= s.charAt(i - 1) && s.charAt(i - 1) <= '9') {
                dp[i] += dp[i - 1];
                dp[i] %= MOD;
            }

            if(i == 1)
                continue;

            String temp = s.substring(i - 2, i);
            int toInt = Integer.parseInt(temp);
            if(10 <= toInt && toInt <= 26) {
                dp[i] += dp[i - 2];
                dp[i] %= MOD;
            }
        }

        bw.write(String.valueOf(dp[s.length()]) + '\n');

        bw.close();
        br.close();
    }
}
