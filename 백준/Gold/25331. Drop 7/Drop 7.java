import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final int[][] map = new int[7][7];

    private static boolean inRange(int y, int x) {
        return 0 <= y && y < 7 && 0 <= x && x < 7;
    }

    private static void moveDown(int[][] _map, int y, int x, int val) {
        int yy = y;
        while (true) {
            if (!inRange(yy + 1, x))
                break;
            if (_map[yy + 1][x] != 0)
                break;

            yy += 1;
        }

        if (yy != y) {
            _map[y][x] = 0;
            _map[yy][x] = val;
        }
    }

    private static boolean validateHorizontal(int[][] _map, int y, int x, int val) {
        int size = 0;

        int xx = x - 1;
        while (xx >= 0) {
            if (_map[y][xx] == 0)
                break;

            size++;
            xx--;
        }

        xx = x + 1;
        while (xx < 7) {
            if (_map[y][xx] == 0)
                break;

            size++;
            xx++;
        }

        return size + 1 == val;
    }

    private static boolean validateVertical(int[][] _map, int y, int x, int val) {
        int size = 0;

        int yy = y - 1;
        while (yy >= 0) {
            if (_map[yy][x] == 0)
                break;

            size++;
            yy--;
        }

        yy = y + 1;
        while (yy < 7) {
            if (_map[yy][x] == 0)
                break;

            size++;
            yy++;
        }

        return size + 1 == val;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tempY = 7;
        for (int y = 0; y < 7; y++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int x = 0; x < 7; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());

                if (map[y][x] != 0)
                    tempY = Math.min(tempY, y);
            }
        }

        tempY = Math.max(0, tempY - 1);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int ball = Integer.parseInt(st.nextToken());

        int ret = 49;
        for (int x = 0; x < 7; x++) {
            int[][] temp = new int[7][7];
            copy(map, temp);

            int y = tempY;
            while (temp[y][x] == 0) {
                if (!inRange(y + 1, x))
                    break;
                if (temp[y + 1][x] != 0)
                    break;

                y += 1;
            }

            temp[y][x] = ball;

            while (true) {
                boolean keep = false;
                List<Pair> candidates = new ArrayList<>();

                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (temp[i][j] == 0)
                            continue;

                        if (validateHorizontal(temp, i, j, temp[i][j]) || validateVertical(temp, i, j, temp[i][j])) {
                            candidates.add(new Pair(i, j));
                            keep = true;
                        }
                    }
                }

                for (Pair pos : candidates)
                    temp[pos.y][pos.x] = 0;

                for (int i = 5; i >= 0; i--) {
                    for (int j = 0; j < 7; j++) {
                        if (temp[i][j] == 0)
                            continue;

                        moveDown(temp, i, j, temp[i][j]);
                    }
                }

                if (!keep)
                    break;
            }

            int count = 49;
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    if (temp[i][j] == 0)
                        count--;
                }
            }

            ret = Math.min(ret, count);
        }

        bw.write(ret + "\n");

        bw.close();
        br.close();
    }

    private static void copy(int[][] src, int[][] dest) {
        for (int y = 0; y < 7; y++) {
            for (int x = 0; x < 7; x++)
                dest[y][x] = src[y][x];
        }
    }

    static class Pair {
        public int y, x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
