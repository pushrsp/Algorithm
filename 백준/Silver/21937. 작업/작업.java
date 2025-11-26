import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M, X;
    private static List<List<Integer>> G = new ArrayList<>();
    private static boolean[] visited = new boolean[100_001];

    private static int go(int curr) {
        visited[curr] = true;
        int ret = 1;
        for (Integer next : G.get(curr)) {
            if (!visited[next]) {
                ret += go(next);
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N; i++) {
            G.add(new ArrayList<>());
        }

        int a, b;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            G.get(b).add(a);
        }

        st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());

        bw.write(String.valueOf(go(X) - 1) + '\n');

        br.close();
        bw.close();
    }
}