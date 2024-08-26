

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[][] ret;
    private static final int[][] dirs = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
    };
    private static Map<String, Integer> dirToInt = new HashMap<>();

    static {
        dirToInt.put("D", 0);
        dirToInt.put("R", 1);
        dirToInt.put("U", 2);
        dirToInt.put("L", 3);
    }

    private static boolean inRange(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < M && ret[y][x] == 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        ret = new int[N][M];

        st = new StringTokenizer(br.readLine());

        String d = st.nextToken();
        int dir = dirToInt.get(d);

        int max = 0;
        if (dir == 0 || dir == 2) {
            max = (M / 2);
            max += M % 2;
            max *= N;
        } else {
            max = (N / 2);
            max += N % 2;
            max *= M;
        }

        int startY = 0, startX = 0;
        if (dir == 0) {
            startX = M / 2;
            startY = N - 1;
        } else if (dir == 1) {
            startY = N / 2;
            startX = M - 1;
        } else if (dir == 2) {
            startX = M / 2;
        } else {
            startY = N / 2;
        }

        ret[startY][startX] = 1;
        int count = 2;
        while (count <= max) {
            int nextY = startY + dirs[dir][0];
            int nextX = startX + dirs[dir][1];

            if (inRange(nextY, nextX)) {
                ret[nextY][nextX] = count++;
                startY = nextY;
                startX = nextX;
            } else {
                dir = (dir + 1) % 4;
            }
        }

        dir = dirToInt.get(d);
        if (dir == 0) {
            startX = M / 2;
            startY = 0;
        } else if (dir == 1) {
            startY = N / 2;
            startX = 0;
        } else if (dir == 2) {
            startY = N - 1;
            startX = M / 2;
        } else {
            startY = N / 2;
            startX = M - 1;
        }

        max = (N * M) - max;
        count = 1;
        while (count <= max) {
            int nextY = startY + dirs[dir][0];
            int nextX = startX + dirs[dir][1];

            if (inRange(nextY, nextX)) {
                ret[nextY][nextX] = ret[startY][startX] + 1;
                count++;
                startY = nextY;
                startX = nextX;
            } else {
                dir--;
                if (dir < 0) {
                    dir = 3;
                }
            }
        }

        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                bw.write(String.valueOf(ret[n][m]) + ' ');
            }
            bw.write('\n');
        }

        br.close();
        bw.close();
    }
}