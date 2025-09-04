import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int N, J, S, H, K;
    private static char[][] G = new char[4][101];
    private static boolean[][][][] VISITED = new boolean[101][201][11][11];

    private static int getObstacleType(int n) {
        if (G[1][n] == '.' && G[2][n] == '.' && G[3][n] == '.') {
            return 0;
        } else if (G[1][n] == '.' && G[2][n] == '.' && G[3][n] == '^') {
            return 1;
        } else if (G[1][n] == '.' && G[2][n] == '^' && G[3][n] == '^') {
            return 2;
        } else {
            return 3;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        J = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int y = 0; y < 3; y++) {
            String s = br.readLine();
            for (int i = 0; i < s.length(); i++) {
                G[y + 1][i + 1] = s.charAt(i);
            }
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{1, H, J, S});
        VISITED[1][H][J][S] = true;

        int ret = -1;
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int n = curr[0];
            int h = curr[1];
            int j = curr[2];
            int s = curr[3];

            if (n == N) {
                ret = Math.max(ret, h);
                continue;
            }

            int obstacleType = getObstacleType(n);
            if (obstacleType == 0) {
                if (!VISITED[n + 1][h][j][s]) {
                    q.add(new int[]{n + 1, h, j, s});
                    VISITED[n + 1][h][j][s] = true;
                }
            } else if (obstacleType == 1) {
                if (j - 1 >= 0 && !VISITED[n + 1][h][j - 1][s]) {
                    q.add(new int[]{n + 1, h, j - 1, s});
                    VISITED[n + 1][h][j - 1][s] = true;
                }

                if (h - K > 0 && !VISITED[n + 1][h - K][j][s]) {
                    q.add(new int[]{n + 1, h - K, j, s});
                    VISITED[n + 1][h - K][j][s] = true;
                }
            } else if (obstacleType == 2) {
                if (j - 2 >= 0 && !VISITED[n + 1][h][j - 2][s]) {
                    q.add(new int[]{n + 1, h, j - 2, s});
                    VISITED[n + 1][h][j - 2][s] = true;
                }

                if (h - K > 0 && !VISITED[n + 1][h - K][j][s]) {
                    q.add(new int[]{n + 1, h - K, j, s});
                    VISITED[n + 1][h - K][j][s] = true;
                }
            } else {
                if (s - 1 >= 0 && !VISITED[n + 1][h][j][s - 1]) {
                    q.add(new int[]{n + 1, h, j, s - 1});
                    VISITED[n + 1][h][j][s - 1] = true;
                }

                if (h - K > 0 && !VISITED[n + 1][h - K][j][s]) {
                    q.add(new int[]{n + 1, h - K, j, s});
                    VISITED[n + 1][h - K][j][s] = true;
                }
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}