import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int K, H;
    private static List<String> commands = new ArrayList<>();
    private static int[][] G = new int[301][301];

    private static int hole(int v, int h) {
        if (h == 0) {
            switch (v) {
                case 0:
                    return 2;
                case 1:
                    return 3;
                case 2:
                    return 0;
                default:
                    return 1;
            }
        } else {
            switch (v) {
                case 0:
                    return 1;
                case 1:
                    return 0;
                case 2:
                    return 3;
                default:
                    return 2;
            }
        }
    }

    private static void go(int i, int y1, int y2, int x1, int x2) {
        if (i == commands.size()) {
            G[y1][x1] = H;
        } else {
            if ("U".equals(commands.get(i))) {
                go(i + 1, y1, (y2 + y1) / 2, x1, x2);

                for (int y = (y2 + y1) / 2 + 1; y <= y2; y++) {
                    for (int x = x1; x <= x2; x++) {
                        G[y][x] = hole(G[(y2 + y1) - y][x], 0);
                    }
                }
            } else if ("D".equals(commands.get(i))) {
                go(i + 1, (y1 + y2) / 2 + 1, y2, x1, x2);

                for (int y = y1; y <= (y2 + y1) / 2; y++) {
                    for (int x = x1; x <= x2; x++) {
                        G[y][x] = hole(G[(y2 + y1) - y][x], 0);
                    }
                }
            } else if ("R".equals(commands.get(i))) {
                go(i + 1, y1, y2, (x1 + x2) / 2 + 1, x2);

                for (int y = y1; y <= y2; y++) {
                    for (int x = x1; x <= (x2 + x1) / 2; x++) {
                        G[y][x] = hole(G[y][(x1 + x2) - x], 1);
                    }
                }
            } else {
                go(i + 1, y1, y2, x1, (x1 + x2) / 2);

                for (int y = y1; y <= y2; y++) {
                    for (int x = (x2 + x1) / 2 + 1; x <= x2; x++) {
                        G[y][x] = hole(G[y][(x1 + x2) - x], 1);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());

        int pow = (int) Math.pow(2, K);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 2 * K; i++) {
            commands.add(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());

        go(0, 1, pow, 1, pow);
        for (int y = 1; y <= pow; y++) {
            for (int x = 1; x <= pow; x++) {
                bw.write(String.valueOf(G[y][x]) + ' ');
            }
            bw.write('\n');
        }

        br.close();
        bw.close();
    }
}