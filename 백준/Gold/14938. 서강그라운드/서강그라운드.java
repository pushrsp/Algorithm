import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, R;
    private static int[][] G = new int[101][101];
    private static int[] A = new int[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < 101; i++) {
            Arrays.fill(G[i], Integer.MAX_VALUE);
        }

        int a, b, d;
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());

            G[a][b] = d;
            G[b][a] = d;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (G[i][k] != Integer.MAX_VALUE && G[k][j] != Integer.MAX_VALUE) {
                        G[i][j] = Math.min(G[i][j], G[i][k] + G[k][j]);
                    }
                }
            }
        }


        int ret = 0;
        for (int i = 1; i <= N; i++) {
            int count = A[i];
            for (int j = 1; j <= N; j++) {
                if (i != j && G[i][j] <= M) {
                    count += A[j];
                }
            }
            ret = Math.max(ret, count);
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}