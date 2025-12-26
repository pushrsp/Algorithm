import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, K, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());

        boolean[] remember = new boolean[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int index = Integer.parseInt(st.nextToken());
            remember[index - 1] = true;
        }
        
        boolean success = true;
        int len = 0;
        int rememberCount = 0;
        for (int i = 0; i < N; i++) {
            if (!remember[i]) {
                len++;
                continue;
            }

            // 기억해야 하는 날과 기억하면 안되는 날이 중간중간 섞여있을 때
            if (len > 0 && rememberCount > 0 && len < K + 1) {
                success = false;
                break;
            }

            len = 0;
            rememberCount++;
        }

        if (len > 0 && rememberCount > 0 && len < K + 1) {
            success = false;
        }

        bw.write(success ? "YES\n" : "NO\n");

        br.close();
        bw.close();
    }
}