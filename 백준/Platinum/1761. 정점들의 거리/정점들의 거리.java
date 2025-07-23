import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static List<List<Node>> G = new ArrayList<>();
    private static int[] DEPTH = new int[400_001];
    private static int[] PARENT = new int[400_001];
    private static int[] DIST = new int[400_001];
    private static boolean[] VISITED = new boolean[400_001];

    static class Node {
        int node, dist;

        Node(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    private static void go(int parent, int depth) {
        for (Node next : G.get(parent)) {
            if (!VISITED[next.node]) {
                VISITED[next.node] = true;
                PARENT[next.node] = parent;
                DEPTH[next.node] = depth + 1;
                DIST[next.node] = next.dist;
                go(next.node, depth + 1);
            }
        }
    }

    private static int dist;

    private static void dfs(int a, int b) {
        if (a == b) {
            return;
        }

        if (DEPTH[a] < DEPTH[b]) {
            dist += DIST[b];
            dfs(a, PARENT[b]);
        } else if (DEPTH[a] > DEPTH[b]) {
            dist += DIST[a];
            dfs(PARENT[a], b);
        } else {
            dist += DIST[b];
            dist += DIST[a];
            dfs(PARENT[a], PARENT[b]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= N; i++) {
            G.add(new ArrayList<>());
        }

        int a, b, d;
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());

            G.get(a).add(new Node(b, d));
            G.get(b).add(new Node(a, d));
        }

        DEPTH[1] = 1;
        VISITED[1] = true;
        PARENT[1] = 1;
        go(1, 1);

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            dist = 0;
            dfs(a, b);
            bw.write(String.valueOf(dist) + '\n');
        }

        br.close();
        bw.close();
    }
}