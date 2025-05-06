import java.util.*;

class Solution {
    
    private static final List<List<Integer>> G = new ArrayList<>();
    private static final Map<Integer, Integer> M = new HashMap<>();
    private static final boolean[] V = new boolean[1_000_001];
    
    static class Tree {
        
        int oddEvenCount;
        int reverseOddEvenCount;
        int nodeCount;
        
        public void increaseNodeCount() {
            nodeCount++;
        }
        
        public void increaseOddEvenCount() {
            oddEvenCount++;
        }
        
        public void increaseReverseOddEvenCount() {
            reverseOddEvenCount++;
        }
        
        public boolean isOddEvenForest() {
            return oddEvenCount == 1 && reverseOddEvenCount == nodeCount - 1;
        }
        
        public boolean isReverseOddEvenForest() {
            return reverseOddEvenCount == 1 && oddEvenCount == nodeCount - 1;
        }
    }
    
    private void go(int curr, Tree tree) {
        if(V[curr]) {
            return;
        }
        
        V[curr] = true;
        tree.increaseNodeCount();
        
        if(curr % 2 == 0 && M.get(curr) % 2 == 0) { //홀짝노드
            tree.increaseOddEvenCount();
        }
        
        if(curr % 2 == 1 && M.get(curr) % 2 == 1) { //홀짝노드
            tree.increaseOddEvenCount();
        }
        
        if(curr % 2 == 0 && M.get(curr) % 2 == 1) { //역홀짝노드
            tree.increaseReverseOddEvenCount();
        }
        
        if(curr % 2 == 1 && M.get(curr) % 2 == 0) { //역홀짝노드
            tree.increaseReverseOddEvenCount();
        }
        
        for(int child: G.get(curr)) {
            go(child, tree);
        }
    }
    
    public int[] solution(int[] nodes, int[][] edges) {
        for(int i = 0; i <= 1_000_000; i ++) {
            G.add(new ArrayList<>());
            M.put(i, 0);
        }
        
        for(int[] edge: edges) {
            int a = edge[0], b = edge[1];
            G.get(a).add(b);
            G.get(b).add(a);
            
            M.replace(a, M.get(a) + 1);
            M.replace(b, M.get(b) + 1);
        }
        
        List<Tree> trees = new ArrayList<>();
        for(int node: nodes) {
            if(V[node]) {
                continue;
            }
            
            Tree tree = new Tree();
            go(node, tree);
            trees.add(tree);
        }
        
        int[] answer = {0, 0};
        for(Tree tree: trees) {
            if(tree.isOddEvenForest()) {
                answer[0]++;
            }
            
            if(tree.isReverseOddEvenForest()) {
                answer[1]++;
            }
        }
        
        
        return answer;
    }
}