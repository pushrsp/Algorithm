import java.io.*;
import java.util.*;

public class Main {

    private static int T;
    private static int[] D1 = new int[2002];
    private static int[] D2 = new int[2002];
    private static int[] D3 = new int[2002];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        int n, m, t, s, g, h, a, b, d;
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());

            s = Integer.parseInt(st.nextToken());
            g = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            List<List<int[]>> adj = new ArrayList<>();
            for (int i = 0; i <= n + 1; i++) {
                adj.add(new ArrayList<>());
            }

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());

                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                d = Integer.parseInt(st.nextToken());

                adj.get(a).add(new int[]{b, d});
                adj.get(b).add(new int[]{a, d});
            }

            List<Integer> candidates = new ArrayList<>();
            for (int i = 0; i < t; i++) {
                candidates.add(Integer.parseInt(br.readLine()));
            }
            Collections.sort(candidates);

            Arrays.fill(D1, Integer.MAX_VALUE);
            D1[s] = 0;

            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[1]));
            pq.add(new int[]{s, 0});

            di(adj, pq, D1);

            Arrays.fill(D2, Integer.MAX_VALUE);
            D2[g] = 0;
            pq.add(new int[]{g, 0});

            di(adj, pq, D2);

            Arrays.fill(D3, Integer.MAX_VALUE);
            D3[h] = 0;
            pq.add(new int[]{h, 0});

            di(adj, pq, D3);

            List<Integer> ret = new ArrayList<>();
            for (int candidate : candidates) {
                if (D1[candidate] == D1[g] + D2[h] + D3[candidate]) {
                    ret.add(candidate);
                    continue;
                }

                if (D1[candidate] == D1[h] + D3[g] + D2[candidate]) {
                    ret.add(candidate);
                    continue;
                }
            }

            for (int ans : ret) {
                bw.write(String.valueOf(ans) + ' ');
            }
            bw.write('\n');
        }

        br.close();
        bw.close();
    }

    private static void di(List<List<int[]>> adj, PriorityQueue<int[]> pq, int[] d1) {
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currNode = curr[0];
            int currDist = curr[1];

            for (int[] next : adj.get(currNode)) {
                int nextNode = next[0];
                int nextDist = next[1] + currDist;

                if (d1[nextNode] > nextDist) {
                    d1[nextNode] = nextDist;
                    pq.add(new int[]{nextNode, nextDist});
                }
            }
        }
    }
}