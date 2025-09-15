import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static int N, M;
    private static long[][] G;
    private static int[][] A;  // 0: 흰색, 1: 검은색
    private static long[][][] DP;  // DP[y][x][0]: 최솟값, DP[y][x][1]: 최댓값
    private static boolean[][][] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        G = new long[N + 1][M + 1];
        A = new int[N + 1][M + 1];
        DP = new long[N + 1][M + 1][2];
        visited = new boolean[N + 1][M + 1][2];

        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 1; x <= M; x++) {
                G[y][x] = Long.parseLong(st.nextToken());
            }
        }

        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 1; x <= M; x++) {
                A[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        DP[1][1][0] = G[1][1];
        DP[1][1][1] = G[1][1];
        visited[1][1][0] = true;
        visited[1][1][1] = true;

        for (int dist = 1; dist <= N + M - 2; dist++) {
            for (int y = 1; y <= N; y++) {
                int x = dist - (y - 1) + 1;
                if (x < 1 || x > M) continue;
                if (y == 1 && x == 1) continue;

                long minVal = Long.MAX_VALUE;
                long maxVal = Long.MIN_VALUE;
                boolean hasPath = false;

                if (y > 1 && visited[y - 1][x][0]) {
                    hasPath = true;
                    for (int i = 0; i < 2; i++) {
                        if (!visited[y - 1][x][i]) continue;

                        long prevVal = DP[y - 1][x][i];
                        long newVal = prevVal + G[y][x];

                        if (A[y][x] == 1) {
                            newVal = -newVal;
                        }

                        minVal = Math.min(minVal, newVal);
                        maxVal = Math.max(maxVal, newVal);
                    }
                }

                if (x > 1 && visited[y][x - 1][0]) {
                    hasPath = true;
                    for (int i = 0; i < 2; i++) {
                        if (!visited[y][x - 1][i]) continue;

                        long prevVal = DP[y][x - 1][i];
                        long newVal = prevVal + G[y][x];

                        if (A[y][x] == 1) {
                            newVal = -newVal;
                        }

                        minVal = Math.min(minVal, newVal);
                        maxVal = Math.max(maxVal, newVal);
                    }
                }

                if (hasPath) {
                    DP[y][x][0] = minVal;
                    DP[y][x][1] = maxVal;
                    visited[y][x][0] = true;
                    visited[y][x][1] = true;
                }
            }
        }

        bw.write(String.valueOf(DP[N][M][1]) + '\n');

        br.close();
        bw.close();
    }
}