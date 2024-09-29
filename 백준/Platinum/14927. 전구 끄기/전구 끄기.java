import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, R = Integer.MAX_VALUE;
    private static int[][] B;
    private static boolean[] C;
    private static int[] DY = {-1, 0, 1, 0, 0};
    private static int[] DX = {0, -1, 0, 1, 0};

    private static boolean inRange(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < N;
    }

    private static void go(int x) {
        if (x == N) {
            check();
            return;
        }

        go(x + 1);
        C[x] = true;
        go(x + 1);
        C[x] = false;
    }

    private static void check() {
        int[][] arr = new int[N][N];
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                arr[y][x] = B[y][x];
            }
        }

        int ret = 0;
        for (int x = 0; x < N; x++) {
            if (!C[x]) {
                continue;
            }
            ret++;
            for (int i = 0; i < 5; i++) {
                int nextY = DY[i];
                int nextX = x + DX[i];
                if (inRange(nextY, nextX)) {
                    arr[nextY][nextX] = (arr[nextY][nextX] + 1) % 2;
                }
            }
        }

        for (int y = 1; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (arr[y - 1][x] == 1) {
                    ret++;
                    for (int i = 0; i < 5; i++) {
                        int nextY = y + DY[i];
                        int nextX = x + DX[i];
                        if (inRange(nextY, nextX)) {
                            arr[nextY][nextX] = (arr[nextY][nextX] + 1) % 2;
                        }
                    }
                }
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (arr[y][x] == 1) {
                    return;
                }
            }
        }

        R = Math.min(R, ret);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        B = new int[N][N];
        C = new boolean[N];

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                B[y][x] = Integer.parseInt(st.nextToken());
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