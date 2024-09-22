import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static boolean[][] ADJ;
    private static int[] cnt;
    private static List<Integer> ret = new ArrayList<>();

    private static void go(int curr) {
        ret.add(curr);

        for (int i = 0; i < N; i++) {
            if (ADJ[curr][i] && cnt[i] < N - 2) {
                cnt[curr]++;
                cnt[i]++;
                ADJ[curr][i] = false;
                ADJ[i][curr] = false;
                go(i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        cnt = new int[N];
        ADJ = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    ADJ[i][j] = true;
                }
            }
        }

        go(0);

        for (int ans : ret) {
            bw.write('a' + String.valueOf(ans + 1) + ' ');
        }

        bw.write("a1\n");

        br.close();
        bw.close();
    }
}