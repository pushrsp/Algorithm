import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static final long mod = 1000000007;
    private static int[][] G = new int[9][100_001];
    private static int N, M;
    private static int[][] D = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
    };
    private static int[] pow = {1, 3, 9, 27, 81};

    private static boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        if (N == 1 && M == 1) {
            bw.write(String.valueOf(1) + '\n');
            br.close();
            bw.close();
            return;
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                int ret = 0;
                for (int[] dir : D) {
                    int nextY = y + dir[0];
                    int nextX = x + dir[1];

                    if (!inRange(nextY, nextX) || G[nextY][nextX] != 0) {
                        continue;
                    } else {
                        ret++;
                    }
                }

                G[y][x] = ret;
            }
        }

        long ret = 1;
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                ret *= pow[G[y][x]];
                ret %= mod;
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}