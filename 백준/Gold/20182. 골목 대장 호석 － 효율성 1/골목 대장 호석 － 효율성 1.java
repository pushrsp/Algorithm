import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static int N, M, A, B, C;
    private static List<List<Point>> adj;
    private static final int[] dist = new int[100001];

    static class Point implements Comparable<Point> {
        int node, cost;

        public Point(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        public int getNode() {
            return node;
        }

        public int getCost() {
            return cost;
        }

        @Override
        public int compareTo(Point o) {
            return Integer.compare(this.cost, o.getCost());
        }
    }

    private static void setDist() {
        Arrays.fill(dist, 987654321);
    }

    private static boolean Di(int start, int dest, int mid) {
        PriorityQueue<Point> pq = new PriorityQueue<>();
        pq.add(new Point(start, 0));

        setDist();
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Point curr = pq.poll();

            for(Point next : adj.get(curr.getNode())) {
                if(next.getCost() > mid)
                    continue;

                int nextDist = curr.getCost() + next.getCost();
                if(nextDist < dist[next.getNode()]) {
                    dist[next.getNode()] = nextDist;
                    pq.add(new Point(next.getNode(), nextDist));
                }
            }
        }

        return dist[dest] <= C;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for (int n = 0; n <= N; n++) {
            adj.add(new ArrayList<>());
        }

        int a, b, c;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            adj.get(a).add(new Point(b, c));
            adj.get(b).add(new Point(a, c));
        }

        int left = 1, right = 1000 * 2, ret = 987654321;
        while (left <= right) {
            int mid = (left + right) / 2;

            if(Di(A, B, mid)) {
                right = mid -1;
                ret = Math.min(ret, mid);
            } else {
                left = mid + 1;
            }
        }

        if(ret == 987654321) {
            bw.write("-1" + '\n');
        } else {
            bw.write(String.valueOf(ret) + '\n');
        }

        bw.close();
        br.close();
    }
}
