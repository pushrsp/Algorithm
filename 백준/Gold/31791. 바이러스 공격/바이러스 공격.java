import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[] DY = {-1, 0, 1, 0};
    private static int[] DX = {0, -1, 0, 1};
    private static int TG, TB, X, B;
    private static int[][] G;

    static boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        G = new int[N + 1][M + 1];

        st = new StringTokenizer(br.readLine());

        TG = Integer.parseInt(st.nextToken());
        TB = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        PriorityQueue<Point> q = new PriorityQueue<>();
        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());

            String s = st.nextToken();
            for (int x = 0; x < M; x++) {
                if (s.charAt(x) == '*') {
                    G[y][x + 1] = 1;
                    q.add(new Point(y, x + 1, 0));
                } else if (s.charAt(x) == '#') {
                    G[y][x + 1] = 2;
                }
            }
        }

        while (!q.isEmpty()) {
            Point curr = q.poll();

            if (curr.t == TG) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nextY = curr.y + DY[i];
                int nextX = curr.x + DX[i];

                if (!inRange(nextY, nextX)) {
                    continue;
                }

                if (G[nextY][nextX] == 1) {
                    continue;
                }

                if (G[nextY][nextX] == 2) {
                    if (curr.t + 1 + TB <= TG) {
                        G[nextY][nextX] = 1;
                        q.add(new Point(nextY, nextX, curr.t + 1 + TB));
                    }
                } else {
                    G[nextY][nextX] = 1;
                    q.add(new Point(nextY, nextX, curr.t + 1));
                }
            }
        }

        List<Point> ret = new ArrayList<>();
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                if (G[y][x] == 0 || G[y][x] == 2) {
                    ret.add(new Point(y, x, 0));
                }
            }
        }

        if (ret.isEmpty()) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            for (Point p : ret) {
                bw.write(String.valueOf(p.y) + ' ' + String.valueOf(p.x) + '\n');
            }
        }
        br.close();
        bw.close();
    }

    static class Point implements Comparable<Point> {
        public int y, x, t;

        Point(int y, int x, int t) {
            this.y = y;
            this.x = x;
            this.t = t;
        }

        @Override
        public int compareTo(Point o) {
            return Integer.compare(t, o.t);
        }
    }
}
