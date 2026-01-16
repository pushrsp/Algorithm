import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[][] city = new int[21][2];
    private static double[][] dist = new double[21][21];
    private static double[][] dp = new double[21][(1 << 16) + 1];

    private static double tsp(int cur, int visited) {
        if (visited == (1 << N) - 1) {
            return dist[cur][0];
        }

        if (dp[cur][visited] != -1) {
            return dp[cur][visited];
        }

        dp[cur][visited] = Double.MAX_VALUE;

        for (int next = 0; next < N; next++) {
            if ((visited & (1 << next)) == 0) {
                double cost = dist[cur][next] + tsp(next, visited | (1 << next));
                dp[cur][visited] = Math.min(dp[cur][visited], cost);
            }
        }

        return dp[cur][visited];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        int x, y;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            city[i][0] = x;
            city[i][1] = y;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int dx = city[i][0] - city[j][0];
                int dy = city[i][1] - city[j][1];
                dist[i][j] = Math.sqrt(dx * dx + dy * dy);
            }
        }

        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }

        bw.write(String.format("%.10f%n", tsp(0, 1)));

        br.close();
        bw.close();
    }
}