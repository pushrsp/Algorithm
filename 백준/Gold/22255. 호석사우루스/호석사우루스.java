import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static int N, M;
    private static int Sx,Sy,Ex,Ey;
    private static int Map[][];
    private static int DP[][][];
    private static List<List<Direction>> Dir = new ArrayList<>();

    private static boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    private static int Di(int startY, int startX) {
        PriorityQueue<Point> pq = new PriorityQueue<>();
        pq.add(new Point(startY, startX, 0, 1));

        DP[startY][startX][1] = 0;

        while (!pq.isEmpty()) {
            Point curr = pq.poll();

            if(curr.y == Ex && curr.x == Ey)
                return curr.sum;

            for(Direction direction : Dir.get(curr.count)) {
                int nextY = curr.y + direction.y, nextX = curr.x + direction.x;

                if(!inRange(nextY, nextX))
                    continue;
                if(Map[nextY][nextX] == -1)
                    continue;

                int nextDist = curr.sum + Map[nextY][nextX];
                if(DP[nextY][nextX][(curr.count + 1) % 3] > nextDist) {
                    DP[nextY][nextX][(curr.count + 1) % 3] = nextDist;
                    pq.add(new Point(nextY, nextX, nextDist,(curr.count + 1) % 3));
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Map = new int[N+1][M+1];
        DP = new int[N+1][M+1][3];

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                DP[i][j][0] = Integer.MAX_VALUE;
                DP[i][j][1] = Integer.MAX_VALUE;
                DP[i][j][2] = Integer.MAX_VALUE;
            }
        }

        st = new StringTokenizer(br.readLine());
        Sx = Integer.parseInt(st.nextToken());
        Sy = Integer.parseInt(st.nextToken());
        Ex = Integer.parseInt(st.nextToken());
        Ey = Integer.parseInt(st.nextToken());

        for (int n = 1; n <= N; n++) {
            st = new StringTokenizer(br.readLine());
            for (int m = 1; m <= M; m++)
                Map[n][m] = Integer.parseInt(st.nextToken());
        }

        List<Direction> dir0 = new ArrayList<>();
        dir0.add(new Direction(-1, 0));
        dir0.add(new Direction(0, -1));
        dir0.add(new Direction(1, 0));
        dir0.add(new Direction(0, 1));

        Dir.add(dir0);

        List<Direction> dir1 = new ArrayList<>();
        dir1.add(new Direction(-1,0));
        dir1.add(new Direction(1,0));

        Dir.add(dir1);

        List<Direction> dir2 = new ArrayList<>();
        dir2.add(new Direction(0,-1));
        dir2.add(new Direction(0,1));

        Dir.add(dir2);

        bw.write(String.valueOf(Di(Sx, Sy)));

        bw.close();
        br.close();
    }

    static class Point implements Comparable<Point> {
        int y, x, sum, count;

        public Point(int y, int x, int sum, int count) {
            this.y = y;
            this.x = x;
            this.sum = sum;
            this.count = count;
        }

        @Override
        public int compareTo(Point o) {
            return Integer.compare(sum, o.sum);
        }
    }

    static class Direction {
        public int y, x;

        public Direction(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
