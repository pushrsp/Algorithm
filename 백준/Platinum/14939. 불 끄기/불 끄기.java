import java.io.*;

public class Main {

    private static int[][] G = new int[10][10];
    private static int[][] D = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
            {0, 0},
    };
    private static boolean[] V = new boolean[10];
    private static int R = Integer.MAX_VALUE;

    private static void go(int x) {
        if (x == 10) {
            check();
            return;
        }

        go(x + 1);
        V[x] = true;
        go(x + 1);
        V[x] = false;
    }

    private static boolean inRange(int y, int x) {
        return 0 <= y && y < 10 && 0 <= x && x < 10;
    }

    private static void check() {
        int[][] arr = new int[10][10];
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                arr[y][x] = G[y][x];
            }
        }

        int cnt = 0;
        for (int x = 0; x < 10; x++) {
            if (!V[x]) {
                continue;
            }
            cnt++;
            for (int i = 0; i < 5; i++) {
                int nextY = D[i][0];
                int nextX = x + D[i][1];

                if (!inRange(nextY, nextX)) {
                    continue;
                }

                arr[nextY][nextX] ^= 1;
            }
        }

        for (int y = 1; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (arr[y - 1][x] == 1) {
                    cnt++;
                    for (int i = 0; i < 5; i++) {
                        int nextY = y + D[i][0];
                        int nextX = x + D[i][1];

                        if (!inRange(nextY, nextX)) {
                            continue;
                        }

                        arr[nextY][nextX] ^= 1;
                    }
                }
            }
        }

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (arr[y][x] == 1) {
                    return;
                }
            }
        }

        R = Math.min(R, cnt);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int y = 0; y < 10; y++) {
            String s = br.readLine();
            for (int x = 0; x < 10; x++) {
                if (s.charAt(x) == '#') {
                    G[y][x] = 0;
                } else {
                    G[y][x] = 1;
                }
            }
        }

        go(0);

        if (R == Integer.MAX_VALUE) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(R) + '\n');
        }

        br.close();
        bw.close();
    }
}