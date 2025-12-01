import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, K;
    private static long[] H = new long[200_001];
    private static List<List<Integer>> G = new ArrayList<>();
    private static boolean[] NON_FLOODED = new boolean[200_001];
    private static boolean[] visited = new boolean[200_001];

    private static void go(int curr, long height) {
        for (Integer next : G.get(curr)) {
            if (visited[next]) {
                continue;
            }

            visited[next] = true;
            NON_FLOODED[next] = NON_FLOODED[curr] && H[next] > height;
            go(next, H[next]);
        }
    }

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

        List<Integer> candidates = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            final int k = Integer.parseInt(st.nextToken());
            NON_FLOODED[k] = true;
            candidates.add(k);
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

//        for (Integer candidate : candidates) {
//            if (visited[candidate]) {
//                continue;
//            } else {
//                visited[candidate] = true;
//                go(candidate, H[candidate]);
//            }
//        }

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