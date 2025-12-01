import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, K;
    private static final long[] H = new long[200_001];
    private static final List<List<Integer>> G = new ArrayList<>();
    private static final boolean[] NON_FLOODED = new boolean[200_001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N; i++) {
            G.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            H[i] = Long.parseLong(st.nextToken());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            G.get(a).add(b);
            G.get(b).add(a);
        }

        K = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            NON_FLOODED[Integer.parseInt(st.nextToken())] = true;
        }

        for (int i = 1; i <= N; i++) {
            if (NON_FLOODED[i]) {
                continue;
            }

            for (Integer child : G.get(i)) {
                if (NON_FLOODED[i]) {
                    break;
                }

                NON_FLOODED[i] = NON_FLOODED[child] && H[i] > H[child];
            }
        }

        boolean ret = true;
        for (int i = 1; i <= N; i++) {
            if (!NON_FLOODED[i]) {
                ret = false;
                break;
            }
        }

        if (ret) {
            bw.write("no flood\n");
        } else {
            bw.write("flood\n");
        }

        br.close();
        bw.close();
    }
}