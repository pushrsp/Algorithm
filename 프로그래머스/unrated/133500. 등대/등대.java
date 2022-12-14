import java.util.ArrayList;

class Solution {
     private final int[][] DP = new int[2][100001];
        private ArrayList<ArrayList<Integer>> Adj;

        void go(int node) {
            DP[1][node] = 1;

            for (int child : Adj.get(node)) {
                if (DP[1][child] == 0) {
                    go(child);
                    DP[0][node] += DP[1][child];
                    DP[1][node] += Math.min(DP[1][child], DP[0][child]);
                }
            }
        }

        public int solution(int n, int[][] lighthouse) {
            Adj = new ArrayList<>();
            for (int i = 0; i <= n; i++)
                Adj.add(new ArrayList<>());

            for (int[] house : lighthouse) {
                int a = house[0], b = house[1];

                Adj.get(a).add(b);
                Adj.get(b).add(a);
            }

            go(1);

            return Math.min(DP[1][1], DP[0][1]);
        }
}