import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, K;
    private static int[][] G = {
            {},
            {-1, 1, 2},
            {-1, 3, 4},
            {-1, 5, 6},
            {-1, 7, 8},
    };

    private static void swap(int y1, int x1, int y2, int x2) {
        int temp = G[y1][x1];
        G[y1][x1] = G[y2][x2];
        G[y2][x2] = temp;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        int hamburger = G[N][M];
        String s = br.readLine();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                swap(1, 1, 3, 1);
                swap(1, 2, 3, 2);

                swap(2, 1, 4, 1);
                swap(2, 2, 4, 2);
            } else if (s.charAt(i) == 'B') {
                swap(1, 1, 2, 2);
                swap(1, 2, 2, 1);

                swap(3, 1, 4, 2);
                swap(3, 2, 4, 1);
            } else if (s.charAt(i) == 'C') {
                swap(2, 1, 3, 2);
                swap(2, 2, 3, 1);

                swap(1, 1, 4, 2);
                swap(1, 2, 4, 1);
            } else {
                G = new int[][]{
                        {},
                        {-1, G[2][1], G[1][1]},
                        {-1, G[3][1], G[1][2]},
                        {-1, G[4][1], G[2][2]},
                        {-1, G[4][2], G[3][2]},
                };
            }
        }

        for (int y = 1; y <= 4; y++) {
            for (int x = 1; x <= 2; x++) {
                if (G[y][x] == hamburger) {
                    bw.write(String.valueOf(y) + ' ' + String.valueOf(x) + '\n');
                    break;
                }
            }
        }

        br.close();
        bw.close();
    }
}