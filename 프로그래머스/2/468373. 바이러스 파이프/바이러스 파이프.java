import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {

    private int K, N, Ans;
    private List<List<Pair>> G = new ArrayList<>();
    private boolean[] visited = new boolean[101];
    private Set<Integer> infected = new HashSet<>();

    private void go(int bridge, int k) {
        for (int nextBridge = 1; nextBridge <= 3; nextBridge++) {
            if (nextBridge != bridge && k + 1 > K) {
                continue;
            }


            Set<Integer> children = new HashSet<>();
            for (Integer i : infected) {
                for (Pair pair : G.get(i)) {
                    if (visited[pair.node] || pair.bridge != nextBridge) {
                        continue;
                    }
                    visited[pair.node] = true;
                    children.add(pair.node);
                }
            }

            if (children.isEmpty()) {
                continue;
            }

            infected.addAll(children);
            Ans = Math.max(Ans, infected.size());
            go(nextBridge, nextBridge != bridge ? k + 1 : k);
            for (Integer child : children) {
                visited[child] = false;
            }
            infected.removeAll(children);
        }
    }

    public int solution(int n, int infection, int[][] edges, int k) {
        K = k;
        N = n;
        for (int i = 0; i <= n; i++) {
            G.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int x = edge[0], y = edge[1], bridge = edge[2];
            G.get(x).add(new Pair(y, bridge));
            G.get(y).add(new Pair(x, bridge));
        }

        visited[infection] = true;
        infected.add(infection);
        go(0, 0);
        return Ans;
    }

    static class Pair {
        int node, bridge;

        Pair(int node, int bridge) {
            this.node = node;
            this.bridge = bridge;
        }
    }
}