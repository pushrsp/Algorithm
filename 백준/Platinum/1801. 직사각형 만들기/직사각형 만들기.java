import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] A = new int[1 << 16];
    private static List<Integer> L = new ArrayList<>();
    private static boolean[] P = new boolean[201];
    private static boolean[] DP = new boolean[1 << 16];
    private static int ans = -1;

    private static void go(int index, int width, int height) {
        if (index == N) {
            if (DP[width] && DP[height]) {
                ans = Math.max(ans, (A[width] / 2) * (A[height] / 2));
            }
            return;
        }
        go(index + 1, width | (1 << index), height);
        go(index + 1, width, height | (1 << index));
        go(index + 1, width, height);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int n = 0; n < N; n++) {
            L.add(Integer.parseInt(st.nextToken()));
        }

        for (int i = 1; i < (1 << N); i++) {
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) != 0) {
                    A[i] += L.get(j);
                }
            }

            // 두 개의 조합으로 나눌 수 없을 때 skip
            if (A[i] % 2 == 1) {
                continue;
            }

            P[0] = true;
            for (int j = 1; j <= A[i] / 2; j++) {
                P[j] = false;
            }
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) != 0) {
                    for (int k = A[i] / 2; k >= L.get(j); k--) {
                        if (P[k - L.get(j)]) {
                            P[k] = true;
                        }
                    }
                }
            }
            if (P[A[i] / 2]) {
                DP[i] = true;
            }
        }

        go(0, 0, 0);
        bw.write(String.valueOf(ans) + '\n');

        br.close();
        bw.close();
    }
}