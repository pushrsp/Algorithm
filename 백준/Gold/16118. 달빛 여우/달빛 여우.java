import java.io.*;
import java.util.*;

public class Main {

    private static int N, M;
    private static List<List<Node>> G = new ArrayList<>();
    private static long[] dist1 = new long[4_001];
    private static long[][] dist2 = new long[2][4_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Arrays.fill(dist1, Long.MAX_VALUE);
        Arrays.fill(dist2[0], Long.MAX_VALUE);
        Arrays.fill(dist2[1], Long.MAX_VALUE);

        for (int i = 0; i <= N; i++) {
            G.add(new ArrayList<>());
        }

        int a, b, d;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());

            G.get(a).add(new Node(b, d * 2L));
            G.get(b).add(new Node(a, d * 2L));
        }

        PriorityQueue<long[]> pq = new PriorityQueue<>((o1, o2) -> Long.compare(o1[1], o2[1]));
        dist1[1] = 0;
        pq.add(new long[]{1, 0});
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            if (dist1[(int) curr[0]] < curr[1]) {
                continue;
            }

            for (Node node : G.get((int) curr[0])) {
                long nextDist = node.dist + curr[1];

                if (dist1[node.node] > nextDist) {
                    dist1[node.node] = nextDist;
                    pq.add(new long[]{node.node, nextDist});
                }
            }
        }

        pq.add(new long[]{1, 0, 0});
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            if (dist2[(int) (curr[2] + 1) % 2][(int) curr[0]] < curr[1]) {
                continue;
            }

            for (Node node : G.get((int) curr[0])) {
                long nextDist = curr[1] + (curr[2] % 2 == 0 ? node.dist / 2 : node.dist * 2);
                if (dist2[(int) curr[2] % 2][node.node] > nextDist) {
                    dist2[(int) curr[2] % 2][node.node] = nextDist;
                    pq.add(new long[]{node.node, nextDist, curr[2] + 1});
                }
            }
        }


        int ret = 0;
        for (int i = 2; i <= N; i++) {
            long fox = dist1[i];
            long wolf = Math.min(dist2[0][i], dist2[1][i]);

            if (fox < wolf) {
                ret++;
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    static class Node {
        int node;
        long dist;

        Node(int node, long dist) {
            this.node = node;
            this.dist = dist;
        }
    }
}