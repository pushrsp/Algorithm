import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static int N;
    private static int[][] Map;
    private static long[][] DP;

    private static boolean InRange(int nowY, int nowX) {
        return 0 <= nowY && nowY <= N && 0 <= nowX && nowX <= N;
    }

    //아래 오른쪽
    private static long go(int nowY, int nowX) {
        if (DP[nowY][nowX] != -1)
            return DP[nowY][nowX];
        if (nowY == N && nowX == N)
            return 1;

        DP[nowY][nowX] = 0;

        int nextY = nowY + Map[nowY][nowX];
        int nextX = nowX + Map[nowY][nowX];

        if (nextY > N && nextX > N)
            return 0;

        if (nextY <= N)
            DP[nowY][nowX] += go(nowY + Map[nowY][nowX], nowX);
        if (nextX <= N)
            DP[nowY][nowX] += go(nowY, nowX + Map[nowY][nowX]);

        return DP[nowY][nowX];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        Map = new int[N + 1][N + 1];
        for (int y = 1; y <= N; y++) {
            st = new StringTokenizer(br.readLine());

            for (int x = 1; x <= N; x++) {
                Map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        DP = new long[N + 1][N + 1];
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                DP[y][x] = -1;
            }
        }

        bw.write(go(1, 1) + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}