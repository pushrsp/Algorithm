import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static void rotate(List<List<Integer>> map) {
        int n = map.size();
        int m = map.get(0).size();

        List<List<Integer>> ret = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                temp.add(map.get(n - 1 - j).get(i));
            }

            ret.add(temp);
        }

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                System.out.print(String.valueOf(ret.get(y).get(x)) + ' ');
            }

            System.out.println();
        }
    }

    static int N, M, T;
    static int[][] G1 = new int[51][51];
    static int[][] G2 = new int[51][51];
    static int[][][] DP = new int[51][51][501];
    static int[] DY = { 0, 1, 1 };
    static int[] DX = { 1, 0, 1 };

    static boolean InRange(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }

    static int go(int y, int x, int t) {
        if (y == N - 1 && x == M - 1) {
            return 0;
        }

        if (t <= 0) {
            return 0;
        }

        if (DP[y][x][t] != -1) {
            return DP[y][x][t];
        }

        int ret = DP[y][x][t] = 0;
        for (int i = 0; i < 3; i++) {
            int nextY = DY[i] + y;
            int nextX = DX[i] + x;
            int nextT = t - 1;

            if (!InRange(nextY, nextX)) {
                continue;
            }

            // 스킵
            ret = Math.max(ret, go(nextY, nextX, nextY));

            // 작업
            int time = G2[nextY][nextX];
            if (nextT - time > 0) {
                ret = Math.max(ret, go(nextY, nextX, nextT - time) + G1[nextY][nextX]);
            }
        }

        DP[y][x][t] = ret;

        return DP[y][x][t];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < M; x++) {
                G1[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < M; x++) {
                G2[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        DP[0][0][0] = 1;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                for (int t = 1; t <= T; t++) {
                    if (y > 0) {
                        if (DP[y - 1][x][t - 1] > 0) {
                            DP[y][x][t] = Math.max(DP[y][x][t], DP[y - 1][x][t - 1]);
                        }
                        if (t >= (G2[y - 1][x] + 1)) {
                            int index = t - (G2[y - 1][x] + 1);
                            if (DP[y - 1][x][index] > 0) {
                                DP[y][x][t] = Math.max(DP[y][x][t], DP[y - 1][x][index] + G1[y - 1][x]);
                            }
                        }
                    }
                    if (x > 0) {
                        if (DP[y][x - 1][t - 1] > 0) {
                            DP[y][x][t] = Math.max(DP[y][x][t], DP[y][x - 1][t - 1]);
                        }
                        if (t >= (G2[y][x - 1] + 1)) {
                            int index = t - (G2[y][x - 1] + 1);
                            if (DP[y][x - 1][index] > 0) {
                                DP[y][x][t] = Math.max(DP[y][x][t], DP[y][x - 1][index] + G1[y][x - 1]);
                            }
                        }
                    }
                    if (y > 0 && x > 0) {
                        if (DP[y - 1][x - 1][t - 1] > 0) {
                            DP[y][x][t] = Math.max(DP[y][x][t], DP[y - 1][x - 1][t - 1]);
                        }
                        if (t >= (G2[y - 1][x - 1] + 1)) {
                            int index = t - (G2[y - 1][x - 1] + 1);
                            if (DP[y - 1][x - 1][index] > 0) {
                                DP[y][x][t] = Math.max(DP[y][x][t], DP[y - 1][x - 1][index] + G1[y - 1][x - 1]);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int t = 0; t <= T; t++) {
            ans = Math.max(ans, DP[N - 1][M - 1][t]);
        }

        bw.write(String.valueOf(ans - 1) + '\n');

        br.close();
        bw.close();
    }
}
