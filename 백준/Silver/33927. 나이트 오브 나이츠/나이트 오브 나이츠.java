import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[][] G = new int[5][5];
    private static int[][] DIR = new int[][]{
            {-2, 1},
            {-2, -1},
            {2, 1},
            {2, -1},
            {1, -2},
            {-1, -2},
            {1, 2},
            {-1, 2},
    };

    private static boolean inRange(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < N;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < N; x++) {
                G[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        int ret = 0;
        for (int i = 1; i <= (1 << (N * N)); i++) {
            List<int[]> candidates = new ArrayList<>();
            for (int j = 0; j <= N * N; j++) {
                if ((i & (1 << j)) != 0) {
                    int y = j / N;
                    int x = j % N;

                    if (inRange(y, x)) {
                        candidates.add(new int[]{j / N, j % N});
                    }
                }
            }

            boolean[][] visited = new boolean[4][4];
            for (int[] candidate : candidates) {
                visited[candidate[0]][candidate[1]] = true;
            }

            boolean isAllEmpty = true;
            int sum = 0;
            for (int[] candidate : candidates) {
                boolean isEmpty = true;
                for (int[] dir : DIR) {
                    int nextY = candidate[0] + dir[0];
                    int nextX = candidate[1] + dir[1];

                    if (!inRange(nextY, nextX)) {
                        continue;
                    }

                    if (visited[nextY][nextX]) {
                        isEmpty = false;
                        break;
                    }
                }

                if (!isEmpty) {
                    isAllEmpty = false;
                    break;
                } else {
                    sum += G[candidate[0]][candidate[1]];
                }
            }

            if (isAllEmpty) {
                ret = Math.max(ret, sum);
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}