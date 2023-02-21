import java.io.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static final Map<String, List<Integer>> map = new HashMap<>();
    private static final int MOD = 1000000007;
    private static int N;
    private static String S;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = br.readLine();

        long ret = 0;
        long w = 0, h = 0, e = 0;
        for (int i = 0; i < N; i++) {
            if (S.charAt(i) == 'W') {
                w += 1;
            } else if (S.charAt(i) == 'H') {
                h += w;
            } else if (S.charAt(i) == 'E') {
                ret = (2 * ret + e) % MOD;
                e += h;
            }
        }

        bw.write(String.valueOf(ret) + "\n");
        bw.close();
        br.close();
    }
}
