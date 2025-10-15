import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, Q;
    private static int[][] G = new int[1_001][1_001];
    private static int[][] DP = new int[1_001][1_001];

    private static int[][] DIR = new int[][]{
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
    };
    private static boolean[][] visited = new boolean[1_001][1_001];

    private static boolean isBorder(int y, int x) {
        return y == 1 || y == N || x == 1 || x == M;
    }

    private static boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Queue<int[]> q = new LinkedList<>();
        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            for (int x = 1; x <= M; x++) {
                G[y][x] = s.charAt(x - 1) - '0';

                if (isBorder(y, x) && G[y][x] == 0) {
                    q.add(new int[]{y, x});
                    visited[y][x] = true;
                }
            }
        }

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int curY = curr[0], curX = curr[1];
            for (int i = 0; i < 4; i++) {
                int nextY = curY + DIR[i][0];
                int nextX = curX + DIR[i][1];

                if (!inRange(nextY, nextX) || visited[nextY][nextX] || G[nextY][nextX] != 0) {
                    continue;
                }

                visited[nextY][nextX] = true;
                q.add(new int[]{nextY, nextX});
            }
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                if (G[y][x] == 1 || (G[y][x] == 0 && !visited[y][x])) {
                    DP[y][x] = 1;
                } else {
                    DP[y][x] = 0;
                }
            }
        }

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                DP[y][x] += DP[y - 1][x] + DP[y][x - 1] - DP[y - 1][x - 1];
            }
        }

        st = new StringTokenizer(br.readLine());

        Q = Integer.parseInt(st.nextToken());

        int y1, y2, x1, x2;
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());

            y1 = Integer.parseInt(st.nextToken());
            x1 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());

            int sum = DP[y2][x2] - DP[y1 - 1][x2] - DP[y2][x1 - 1] + DP[y1 - 1][x1 - 1];

            if (sum == 0) {
                bw.write("Yes\n");
            } else {
                bw.write("No " + sum + "\n");
            }
        }

        bw.close();
        br.close();
    }
}