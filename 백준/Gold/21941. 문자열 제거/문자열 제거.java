import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static final int MOD = 1000000;

    private static String s;
    private static int[] dp = new int[5001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String s = st.nextToken();

        st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());

        Map<String, Integer> map = new HashMap<>();
        for(int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());

            String word = st.nextToken();
            Integer score = Integer.parseInt(st.nextToken());

            map.put(word, score);
        }

        dp[0] = 0;
        for(int i = 1; i <= s.length(); i++) {
            dp[i] = dp[i - 1] + 1;

            for(int lastLen = 1; lastLen <= i; lastLen++) {
                String lastWord = s.substring(i - lastLen, i);

                if(map.containsKey(lastWord))
                    dp[i] = Math.max(dp[i], dp[i - lastLen] + map.get(lastWord));
            }
        }

        bw.write(String.valueOf(dp[s.length()]) + '\n');

        bw.close();
        br.close();
    }
}
