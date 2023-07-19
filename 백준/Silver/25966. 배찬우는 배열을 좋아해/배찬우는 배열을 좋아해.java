import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static int N, M, Q;
    private static int map[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < M; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        int cmd, i, j, k;
        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            cmd = Integer.parseInt(st.nextToken());
            i = Integer.parseInt(st.nextToken());
            j = Integer.parseInt(st.nextToken());

            if(cmd == 0) {
                k = Integer.parseInt(st.nextToken());
                map[i][j] = k;
            } else {
                int[] temp = map[i];
                map[i] = map[j];
                map[j] = temp;
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                bw.write(String.valueOf(map[y][x]) + ' ');
            }
            bw.write('\n');
        }

        bw.close();
        br.close();
    }
}
