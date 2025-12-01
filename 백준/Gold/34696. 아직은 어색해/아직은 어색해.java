import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static boolean[] visited = new boolean[100_001];
    private static long[] DIST = new long[100_001];

    private static long dist(long[] c1, long[] c2) {
        long dx = c1[0] - c2[0];
        long dy = c1[1] - c2[1];
        return dx * dx + dy * dy;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        List<long[]> seats = new ArrayList<>();
        seats.add(new long[]{-1, -1});

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            seats.add(new long[]{x, y});
        }

        int taken = Integer.parseInt(br.readLine());
        visited[taken] = true;

        for (int i = 1; i <= M; i++) {
            DIST[i] = dist(seats.get(taken), seats.get(i));
        }

        bw.write(String.valueOf(taken) + '\n');
        for (int i = 2; i <= N; i++) {
            long maxDist = -1;
            int index = -1;
            for (int j = 1; j <= M; j++) {
                if (!visited[j]) {
                    if (DIST[j] > maxDist) {
                        maxDist = DIST[j];
                        index = j;
                    }
                }
            }

            bw.write(String.valueOf(index) + '\n');
            visited[index] = true;
            for (int j = 1; j <= M; j++) {
                if (!visited[j]) {
                    long d2 = dist(seats.get(index), seats.get(j));
                    DIST[j] = Math.min(DIST[j], d2);
                }
            }
        }

        br.close();
        bw.close();
    }
}