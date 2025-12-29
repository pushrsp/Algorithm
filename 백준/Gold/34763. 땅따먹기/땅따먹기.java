import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T, N, K, C;

    private static boolean go() {
        // K의 약수 w를 찾아서 w + (K/w) - 1 = N 인지 확인
        for (long w = 1; w * w <= K; w++) {
            if (K % w == 0) {
                long h = K / w;
                if (w + h - 1 == N) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            bw.write(go() ? "YES\n" : "NO\n");
        }

        br.close();
        bw.close();
    }
}