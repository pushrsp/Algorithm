import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, K;
    private static final int[][] G = new int[1002][1002];
    private static final boolean[][] V = new boolean[1002][1002];
    private static final int[] DY = {-1, 0, 1, 0};
    private static final int[] DX = {0, -1, 0, 1};

    private static void reset() {
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                V[y][x] = false;
            }
        }
    }

    private static boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    private static boolean check(int mid) {
        Queue<Pair> q = new LinkedList<>();
        for (int y = 1; y <= N; y++) {
            if (G[y][1] <= mid) {
                q.add(new Pair(y, 1));
                V[y][1] = true;
            }

            if (G[y][M] <= mid) {
                q.add(new Pair(y, M));
                V[y][M] = true;
            }
        }

        for (int x = 2; x <= M - 1; x++) {
            if (G[1][x] <= mid) {
                q.add(new Pair(1, x));
                V[1][x] = true;
            }
        }
        int k = q.size();
        while (!q.isEmpty()) {
            Pair curr = q.poll();
            for (int i = 0; i < 4; i++) {
                int nextY = curr.y + DY[i];
                int nextX = curr.x + DX[i];
                if (inRange(nextY, nextX) && !V[nextY][nextX] && G[nextY][nextX] <= mid) {
                    V[nextY][nextX] = true;
                    q.add(new Pair(nextY, nextX));
                    k++;
                }
            }
        }
        return k >= K;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE, mid;
        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 1; x <= M; x++) {
                G[y][x] = Integer.parseInt(st.nextToken());
                left = Math.min(left, G[y][x]);
                right = Math.max(right, G[y][x]);
            }
        }

        while (left <= right) {
            reset();
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        bw.write(String.valueOf(left) + '\n');

        br.close();
        bw.close();
    }
}