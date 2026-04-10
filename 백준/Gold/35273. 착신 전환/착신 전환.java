import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static boolean[] visited = new boolean[1_000_001];
    private static int[] color = new int[1_000_001];
    private static List<List<Integer>> G1 = new ArrayList<>();
    private static List<List<Integer>> G2 = new ArrayList<>();
    private static int[] memo = new int[1_000_001];

    private static void go(int origin, int curr, int c) {
        for (Integer next : G1.get(curr)) {
            if (color[next] != 0) {
                continue;
            }

            if (visited[next]) {
                if (next == origin) {
                    color[curr] = color[origin] = c;
                    G2.get(origin).add(curr);
                }
            } else {
                visited[next] = true;
                go(origin, next, c);
                visited[next] = false;
                if (color[next] != 0) {
                    color[curr] = c;
                    G2.get(next).add(curr);
                }
            }
        }
    }

    private static int go(int curr, int prev) {
        if (curr == prev) {
            return curr;
        }
        if (memo[curr] != 0) {
            return memo[curr];
        }
        if (color[curr] != 0) {
            return memo[curr] = G2.get(curr).get(0);
        } else {
            return memo[curr] = go(G1.get(curr).get(0), curr);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= N; i++) {
            G1.add(new ArrayList<>());
            G2.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int j = Integer.parseInt(st.nextToken());
            G1.get(i).add(j);
        }

        int[] indeg = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            int target = G1.get(i).get(0);
            if (target != i) indeg[target]++;
        }

        boolean[] isTail = new boolean[N + 1];
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            if (G1.get(i).get(0) != i && indeg[i] == 0) queue.add(i);
        }
        while (!queue.isEmpty()) {
            int u = queue.poll();
            isTail[u] = true;
            int v = G1.get(u).get(0);
            indeg[v]--;
            if (indeg[v] == 0) queue.add(v);
        }

        int c = 1;
        for (int i = 1; i <= N; i++) {
            if (i == G1.get(i).get(0) || color[i] != 0 || isTail[i]) {
                continue;
            } else {
                visited[i] = true;
                go(i, i, c++);
                visited[i] = false;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (i == G1.get(i).get(0)) {
                bw.write(String.valueOf(i) + ' ');
            } else {
                bw.write(String.valueOf(go(i, -1)) + ' ');
            }
        }

        br.close();
        bw.close();
    }
}