import java.io.*;
import java.util.*;

public class Main {

    private static int N, M;
    private static List<List<Pair>> G = new ArrayList<>();
    private static int[] D1 = new int[1_001];
    private static int[] H1 = new int[1_001];
    private static int[] D2 = new int[1_001];
    private static boolean[][] V = new boolean[1_001][1_001];

    static class Pair {
        int node, dist;

        Pair(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    static class P1 {
        int next, dist;

        P1(int next, int dist) {
            this.next = next;
            this.dist = dist;
        }
    }

    static class P2 {
        int n1, n2;

        P2(int n1, int n2) {
            this.n1 = n1;
            this.n2 = n2;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Arrays.fill(D1, Integer.MAX_VALUE);

        for (int n = 0; n <= N; n++) {
            G.add(new ArrayList<>());
        }

        int a, b, t;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            G.get(a).add(new Pair(b, t));
            G.get(b).add(new Pair(a, t));
        }

        PriorityQueue<P1> pq1 = new PriorityQueue<>(Comparator.comparingInt(p -> p.dist));
        pq1.add(new P1(1, 0));
        D1[1] = 0;
        H1[1] = 1;

        while (!pq1.isEmpty()) {
            final P1 point = pq1.poll();
            for (Pair pair : G.get(point.next)) {
                int nextDist = pair.dist + point.dist;
                if (nextDist < D1[pair.node]) {
                    pq1.add(new P1(pair.node, nextDist));
                    D1[pair.node] = nextDist;
                    H1[pair.node] = point.next;
                }
            }
        }

        if (D1[N] == Integer.MAX_VALUE) {
            bw.write(String.valueOf(-1) + '\n');
            br.close();
            bw.close();
            return;
        }

        int current = N;
        List<P2> candidates = new ArrayList<>();
        while (H1[current] != current) {
            candidates.add(new P2(H1[current], current));
            current = H1[current];
        }

        int ret = 0;
        for (P2 candidate : candidates) {
            V[candidate.n1][candidate.n2] = true;
            V[candidate.n2][candidate.n1] = true;

            Arrays.fill(D2, Integer.MAX_VALUE);

            PriorityQueue<P1> pq2 = new PriorityQueue<>(Comparator.comparingInt(p -> p.dist));
            D2[1] = 0;
            pq2.add(new P1(1, 0));

            while (!pq2.isEmpty()) {
                final P1 point = pq2.poll();
                for (Pair pair : G.get(point.next)) {
                    if (V[point.next][pair.node] || V[pair.node][point.next]) {
                        continue;
                    }

                    int nextDist = pair.dist + point.dist;
                    if (nextDist < D2[pair.node]) {
                        pq2.add(new P1(pair.node, nextDist));
                        D2[pair.node] = nextDist;
                    }
                }
            }

            if (D1[N] < D2[N]) {
                ret = Math.max(ret, D2[N] - D1[N]);
            }

            V[candidate.n1][candidate.n2] = false;
            V[candidate.n2][candidate.n1] = false;
        }

        if (ret >= 5000 * 10_000) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(ret) + '\n');
        }

        br.close();
        bw.close();
    }
}