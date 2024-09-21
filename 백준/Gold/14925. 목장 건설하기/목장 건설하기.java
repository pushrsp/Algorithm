import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int M, N;
    private static int[][] G, DP;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        G = new int[M + 1][N + 1];
        DP = new int[M + 1][N + 1];

        for (int y = 1; y <= M; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 1; x <= N; x++) {
                G[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        int ret = 0;
        for (int y = 1; y <= M; y++) {
            for (int x = 1; x <= N; x++) {
                if (G[y][x] != 0) {
                    DP[y][x] = 0;
                } else {
                    DP[y][x] = Math.min(Math.min(DP[y - 1][x], DP[y][x - 1]), DP[y - 1][x - 1]) + 1;
                }
                ret = Math.max(ret, DP[y][x]);
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}