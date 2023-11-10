import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N, M, Q;
    private static int[][] arr = new int[2001][2001];
    private static int[][] sum = new int[2001][2001];


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br, bw);

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br, BufferedWriter bw) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        for (int n = 1; n <= N; n++) {
            st = new StringTokenizer(br.readLine());

            for (int m = 1; m <= M; m++) {
                arr[n][m] = Integer.parseInt(st.nextToken());
                sum[n][m] = sum[n - 1][m] + arr[n][m];
            }
        }

        for (int n = 1; n <= N; n++) {
            for (int m = 1; m <= M; m++) {
                sum[n][m] += sum[n - 1][m - 1];
            }
        }

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());

            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            bw.write(String.valueOf(sum[y][x]) + '\n');
        }
    }
}
