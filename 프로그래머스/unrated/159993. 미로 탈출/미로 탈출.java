import java.io.IOException;
import java.util.Arrays;
import java.util.PriorityQueue;

 class Solution {
        private static final int INF = 987654321;
        private static final int[] DY = {-1, 0, 1, 0};
        private static final int[] DX = {0, -1, 0, 1};
        private static int Y, X;
        private static int startY, startX, endY, endX, leverY, leverX;
        private static String[] map;
        private static int[][] dist;

        private boolean inRange(int y, int x) {
            return 0 <= y && y < Y && 0 <= x && x < X;
        }

        private int di(int beginY, int beginX, int destY, int destX) {
            PriorityQueue<Point> pq = new PriorityQueue<>();

            dist[beginY][beginX] = 0;
            pq.add(new Point(beginY, beginX, 0));

            while (!pq.isEmpty()) {
                Point cur = pq.poll();

                for (int i = 0; i < 4; i++) {
                    int nextY = cur.y + DY[i], nextX = cur.x + DX[i];

                    if (!inRange(nextY, nextX))
                        continue;
                    if (map[nextY].charAt(nextX) == 'X')
                        continue;
                    if (dist[nextY][nextX] > cur.dist + 1) {
                        dist[nextY][nextX] = cur.dist + 1;
                        pq.add(new Point(nextY, nextX, cur.dist + 1));
                    }
                }
            }

            return dist[destY][destX];
        }

        private void fill() {
            for (int y = 0; y < Y; y++)
                Arrays.fill(dist[y], INF);
        }

        public int solution(String[] maps) {
            Y = maps.length;
            X = maps[0].length();

            map = new String[Y];
            for (int y = 0; y < Y; y++) {
                map[y] = maps[y];

                for (int x = 0; x < X; x++) {
                    if (map[y].charAt(x) == 'S') {
                        startY = y;
                        startX = x;
                    } else if (map[y].charAt(x) == 'E') {
                        endY = y;
                        endX = x;
                    } else if (map[y].charAt(x) == 'L') {
                        leverY = y;
                        leverX = x;
                    }
                }
            }

            dist = new int[Y][X];
            fill();

            int toLever = di(startY, startX, leverY, leverX);
            if (toLever == INF)
                return -1;

            fill();
            int toEnd = di(leverY, leverX, endY, endX);
            if (toEnd == INF)
                return -1;

            return toLever + toEnd;
        }

        private static class Point implements Comparable<Point> {
            public int y, x, dist;

            public Point(int y, int x, int dist) {
                this.y = y;
                this.x = x;
                this.dist = dist;
            }

            @Override
            public int compareTo(Point o) {
                if (dist < o.dist)
                    return -1;
                else if (dist > o.dist)
                    return 1;
                else
                    return 0;
            }

        }
    }