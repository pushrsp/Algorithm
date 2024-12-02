import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[] DP = new int[20001];
    private static List<Integer> W = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Arrays.fill(DP, 9999999);

        st = new StringTokenizer(br.readLine());

        W.add(0);
        for (int m = 1; m <= M; m++) {
            W.add(Integer.parseInt(st.nextToken()));
        }

        for (int i = 0; i < W.size(); i++) {
            for (int j = i + 1; j < W.size(); j++) {
                DP[W.get(i) + W.get(j)] = 1;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (DP[i] != 9999999) {
                continue;
            }

            for (int j = 1; j < i; j++) {
                if (DP[j] == 9999999 || DP[i - j] == 9999999) {
                    continue;
                }
                DP[i] = Math.min(DP[i], DP[j] + DP[i - j]);
            }
        }

        if (DP[N] == 9999999) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(DP[N]) + '\n');
        }

        br.close();
        bw.close();
    }
}