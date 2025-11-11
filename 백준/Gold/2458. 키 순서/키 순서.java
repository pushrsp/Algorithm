import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static boolean[][] G = new boolean[501][501];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            G[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = true;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (G[i][k] && G[k][j]) {
                        G[i][j] = true;
                    }
                }
            }
        }

        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (G[i][j] || G[j][i]) {
                    arr[i]++;
                }
            }
        }

        int ret = 0;
        for (int i = 1; i <= N; i++) {
            if (arr[i] == N - 1) {
                ret++;
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}