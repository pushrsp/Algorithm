import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T, N;

    private static int score(String a, String b, String c) {
        int score = 0;
        for (int i = 0; i < 4; i++) {
            score += a.charAt(i) != b.charAt(i) ? 1 : 0;
            score += b.charAt(i) != c.charAt(i) ? 1 : 0;
            score += c.charAt(i) != a.charAt(i) ? 1 : 0;
        }

        return score;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            String[] arr = new String[N];

            st = new StringTokenizer(br.readLine());
            for (int n = 0; n < N; n++) {
                arr[n] = st.nextToken();
            }

            if (N > 32) {
                bw.write(String.valueOf(0) + '\n');
                continue;
            }

            int ret = Integer.MAX_VALUE;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    for (int k = j + 1; k < N; k++) {
                        ret = Math.min(ret, score(arr[i], arr[j], arr[k]));
                    }
                }
            }

            bw.write(String.valueOf(ret) + '\n');
        }

        br.close();
        bw.close();
    }
}
