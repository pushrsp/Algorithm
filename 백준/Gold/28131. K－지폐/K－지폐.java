import java.awt.*;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static int N, M, K, S, T;
    private static int[][] DP = new int[100001][51];
    private static List<List<Point>> adj = new ArrayList<>();

    private static void setDp() {
        for (int i = 0; i < 100001; i++) {
            Arrays.fill(DP[i], Integer.MAX_VALUE);
        }
    }

    private static int di(int start, int dest) {
        PriorityQueue<Point> pq = new PriorityQueue<>();

        setDp();
        DP[start][0] = 0;
        pq.add(new Point(start, 0));

        while (!pq.isEmpty()) {
            Point curr = pq.poll();

            if(curr.node == dest && curr.cost % K == 0)
                return curr.cost;

            for(Point next : adj.get(curr.node)) {
                int nextDist = next.cost + curr.cost;
                if(nextDist < DP[next.node][nextDist % K]) {
                    pq.add(new Point(next.node, nextDist));
                    DP[next.node][nextDist % K] = nextDist;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int n = 0; n <= N; n++)
            adj.add(new ArrayList<>());

        st = new StringTokenizer(br.readLine());

        S = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        int u, v, w;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());

            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            adj.get(u).add(new Point(v, w));
        }

        int ret = di(S, T);
        if(ret == -1)
            System.out.println("IMPOSSIBLE");
        else
            System.out.println(ret);
        
        bw.close();
        br.close();
    }

    static class Point implements Comparable<Point> {
        public int node, cost;

        public Point(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Point o) {
            return Integer.compare(cost, o.cost);
        }
    }
}
