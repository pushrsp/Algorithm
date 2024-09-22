import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int C, H, K;
    private static boolean[] V;
    private static List<List<Integer>> G = new ArrayList<>();
    private static int S;

    private static void go1(int curr) {
        V[curr] = true;
        for (int next : G.get(curr)) {
            if (!V[next]) {
                go1(next);
            }
        }
    }

    private static void go2(int curr) {
        S++;
        V[curr] = true;
        for (int next : G.get(curr)) {
            if (!V[next]) {
                go2(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = new boolean[N + 1];
        for (int n = 0; n <= N; n++) {
            G.add(new ArrayList<>());
        }

        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            G.get(x).add(y);
            G.get(y).add(x);
        }

        st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        go1(H);

        go2(C);
        int ret = S;
        S = 0;

        List<Integer> candidates = new ArrayList<>();
        for (int n = 1; n <= N; n++) {
            if (!V[n]) {
                S = 0;
                go2(n);
                candidates.add(S);
            }
        }

        Collections.sort(candidates, Collections.reverseOrder());

        for (int i = 0; i < Math.min(K, candidates.size()); i++) {
            ret += candidates.get(i);
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}