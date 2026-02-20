import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        int totalNodes = N + M + 1;

        List<List<int[]>> graph = new ArrayList<>();
        int[] inDegree = new int[totalNodes];

        for (int i = 0; i < totalNodes; i++) {
            graph.add(new ArrayList<>());
        }

        int[][] edges = new int[E][3];

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            if (u < 0) u = N + Math.abs(u);
            if (v < 0) v = N + Math.abs(v);

            edges[i][0] = u;
            edges[i][1] = v;
            edges[i][2] = w;

            graph.get(u).add(new int[]{v, w});
            inDegree[v]++;
        }

        long[] blackHoleSize = new long[totalNodes];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            blackHoleSize[N + 1 + i] = Long.parseLong(st.nextToken());
        }

        int D = Integer.parseInt(br.readLine().trim());

        long minW = Long.MAX_VALUE;
        for (int i = 0; i < E; i++) {
            if (edges[i][0] == D || edges[i][1] == D) {
                minW = Math.min(minW, edges[i][2]);
            }
        }

        if (minW == Long.MAX_VALUE) {
            bw.write("SAD\n");
            br.close();
            bw.close();
            return;
        }

        long[] dp = new long[totalNodes];
        Arrays.fill(dp, -1);
        dp[1] = 0;

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i < totalNodes; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }

        long maxT = 0;

        while (!queue.isEmpty()) {
            int curr = queue.poll();

            if (curr > N && dp[curr] >= 0) {
                dp[curr] += blackHoleSize[curr];
            }

            if (dp[curr] >= 0) {
                maxT = Math.max(maxT, dp[curr]);
            }

            for (int[] next : graph.get(curr)) {
                int nextNode = next[0];

                if (dp[curr] >= 0) {
                    dp[nextNode] = Math.max(dp[nextNode], dp[curr]);
                }

                inDegree[nextNode]--;
                if (inDegree[nextNode] == 0) {
                    queue.add(nextNode);
                }
            }
        }

        bw.write(maxT >= minW ? "HAPPY\n" : "SAD\n");
        br.close();
        bw.close();
    }
}