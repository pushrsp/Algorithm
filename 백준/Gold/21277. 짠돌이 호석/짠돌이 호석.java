import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static int N1, M1, N2, M2;
    private static int[][] board, b1, b2;
    private static int ans = 987654321;

    private static void rotate() {
        int[][] temp = new int[51][51];
        for (int y = 0; y < M1; y++) {
            for (int x = 0; x < N1; x++) {
                temp[y][x] = b1[N1 - 1 - x][y];
            }
        }

        for (int y = 0; y <= 50; y++) {
            for (int x = 0; x <= 50; x++) {
                b1[y][x] = temp[y][x];
            }
        }

        int t = N1;
        N1 = M1;
        M1 = t;
    }

    private static void go(int yy, int xx) {
        boolean success = true;
        for (int y = yy; y < yy + N1; y++) {
            for (int x = xx; x < xx + M1; x++) {
                if(board[y][x] == 1 && b1[y - yy][x - xx] == 1) {
                    success = false;
                    break;
                }
            }

            if(!success) {
                break;
            }
        }

        if(success) {
            int minY = Math.min(yy, 50);
            int maxY = Math.max(yy + N1 - 1, 49 + N2);
            int minX = Math.min(xx, 50);
            int maxX = Math.max(xx + M1 -1, 49 + M2);

            int area = (maxY - minY + 1) * (maxX - minX + 1);
            ans = Math.min(ans, area);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N1 = Integer.parseInt(st.nextToken());
        M1 = Integer.parseInt(st.nextToken());

        b1 = new int[51][51];
        for (int y = 0; y < N1; y++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();

            for (int x = 0; x < M1; x++) {
                b1[y][x] = Integer.parseInt(String.valueOf(s.charAt(x)));
            }
        }

        st = new StringTokenizer(br.readLine());
        N2 = Integer.parseInt(st.nextToken());
        M2 = Integer.parseInt(st.nextToken());

        b2 = new int[51][51];
        for (int y = 0; y < N2; y++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();

            for (int x = 0; x < M2; x++) {
                b2[y][x] = Integer.parseInt(String.valueOf(s.charAt(x)));
            }
        }

        board = new int[151][151];

        for (int y = 50; y < 50 + N2; y++) {
            for (int x = 50; x < 50 + M2; x++) {
                board[y][x] = b2[y - 50][x - 50];
            }
        }

        for (int i = 0; i < 4; i++) {
            rotate();

            for (int j = 0; j < 100; j++) {
                for (int k = 0; k < 100; k++) {
                    go(j,k);
                }
            }
        }

        bw.write(ans + "\n");

        bw.close();
        br.close();
    }
}
