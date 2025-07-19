import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[][] G = new int[701][701];

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        for (int y = 1; y <= M; y++) {
            for (int x = 1; x <= M; x++) {
                G[y][x] = 1;
            }
        }

        List<Pair> pairs = new ArrayList<>();
        for (int y = M; y >= 1; y--) {
            pairs.add(new Pair(y, 1));
        }
        for (int x = 2; x <= M; x++) {
            pairs.add(new Pair(1, x));
        }

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            int z = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            int index = z;
            for (int j = 0; j < o; j++, index++) {
                G[pairs.get(index).y][pairs.get(index).x] += 1;
            }

            for (int j = 0; j < t; j++, index++) {
                G[pairs.get(index).y][pairs.get(index).x] += 2;
            }
        }

        List<Pair> search = new ArrayList<>();
        search.add(new Pair(0, -1));
        search.add(new Pair(-1, -1));
        search.add(new Pair(-1, 0));

        for (int y = 2; y <= M; y++) {
            for (int x = 2; x <= M; x++) {
                for (Pair pair : search) {
                    G[y][x] = Math.max(G[y][x], G[y + pair.y][x + pair.x]);
                }
            }
        }

        for (int y = 1; y <= M; y++) {
            for (int x = 1; x <= M; x++) {
                if (x < M) {
                    bw.write(String.valueOf(G[y][x]) + ' ');
                } else {
                    bw.write(String.valueOf(G[y][x]));
                }
            }
            bw.write('\n');
        }

        br.close();
        bw.close();
    }
}