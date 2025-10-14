import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static String[] male = new String[11];
    private static String[] female = new String[11];
    private static int[] DP = new int[1 << 10];

    private static int score(String s1, String s2) {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                ret += 1;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            male[i] = st.nextToken();
        }

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            female[i] = st.nextToken();
        }

        for (int i = 0; i < (1 << N); i++) {
            DP[i] = -1;
        }
        DP[0] = 0;

        for (int mask = 0; mask < (1 << N); mask++) {
            if (DP[mask] == -1) continue;
            
            int maleIdx = Integer.bitCount(mask);
            
            if (maleIdx >= N) continue;
            
            for (int femaleIdx = 0; femaleIdx < N; femaleIdx++) {
                if ((mask & (1 << femaleIdx)) != 0) continue;
                
                int newMask = mask | (1 << femaleIdx);
                int newScore = DP[mask] + score(male[maleIdx], female[femaleIdx]);
                DP[newMask] = Math.max(DP[newMask], newScore);
            }
        }

        bw.write(String.valueOf(DP[(1 << N) - 1]) + '\n');

        br.close();
        bw.close();
    }
}