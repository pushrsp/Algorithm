

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static final int INF = 987654321;
    public static int V, E;
    public static int[][] Dist;

    public static void Floyd() {
        for (int k = 1; k <= V; k++) {
            for (int i = 1; i <= V; i++) {
                for (int j = 1; j <= V; j++) {
                    if (i == j)
                        continue;

                    Dist[i][j] = Math.min(Dist[i][j], Dist[i][k] + Dist[k][j]);
                }
            }
        }
    }

    public static int GetResult() {
        int ret = INF;
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (i == j)
                    continue;

                if (Dist[i][j] != INF && Dist[j][i] != INF)
                    ret = Math.min(ret, Dist[i][j] + Dist[j][i]);
            }
        }

        return ret == INF ? -1 : ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        Dist = new int[V + 1][V + 1];

        for (int v = 0; v <= V; v++)
            Arrays.fill(Dist[v], INF);

        int a, b, c;
        for (int e = 0; e < E; e++) {
            st = new StringTokenizer(br.readLine(), " ");

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            Dist[a][b] = c;
        }

        Floyd();
        System.out.println(GetResult());
    }
}
