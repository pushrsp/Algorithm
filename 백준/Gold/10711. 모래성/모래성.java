import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int H, W;

    private static int[][] G = new int[1_001][1_001];
    private static int[][] DIR = {
            {-1, 0},
            {-1, -1},
            {0, -1},
            {1, -1},
            {1, 0},
            {1, 1},
            {0, 1},
            {-1, 1},
    };

    private static boolean inRange(int y, int x) {
        return 1 <= y && y <= H && 1 <= x && x <= W;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        Queue<int[]> q = new LinkedList<>();
        for (int y = 1; y <= H; y++) {
            String s = br.readLine();
            for (int x = 1; x <= W; x++) {
                if (s.charAt(x - 1) == '.') {
                    G[y][x] = 0;
                    q.add(new int[]{y, x});
                } else {
                    G[y][x] = s.charAt(x - 1) - '0';
                }
            }
        }

        int ret = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] curr = q.poll();
                for (int[] dir : DIR) {
                    int nextY = curr[0] + dir[0];
                    int nextX = curr[1] + dir[1];

                    if (inRange(nextY, nextX) && G[nextY][nextX] > 0) {
                        G[nextY][nextX] -= 1;
                        if (G[nextY][nextX] == 0) {
                            q.add(new int[]{nextY, nextX});
                        }
                    }
                }
            }
            ret++;
        }

        bw.write(String.valueOf(ret - 1) + '\n');
        br.close();
        bw.close();
    }
}