import java.util.*;

class Solution {
    
    private Map<Integer, List<Integer>> m = new HashMap<>();
    private List<Component> components = new ArrayList<>();
    private boolean[] visited = new boolean[1_000_001];
    
    private void go(int curr, Component component) {
        visited[curr] = true;
        int degree = m.get(curr).size();
        
        // normal even
        if((curr % 2 == 0) && (degree % 2 == 0)) {
            component.normalEven++;
        }
        
        // normal odd
        if((curr % 2 == 1) && (degree % 2 == 1)) {
            component.normalOdd++;
        }
        
        // reverse even
        if((curr % 2 == 0) && (degree % 2 == 1)) {
            component.reverseEven++;
        }
        
        // reverse odd
        if((curr % 2 == 1) && (degree % 2 == 0)) {
            component.reverseOdd++;
        }
        
        for(int child: m.get(curr)) {
            if(!visited[child]) {
                go(child, component);
            }
        }
    }
    
    public int[] solution(int[] nodes, int[][] edges) {
        for(int node: nodes) {
            m.put(node, new ArrayList<>());
        }
        
        for(int[] edge: edges) {
            int x = edge[0], y = edge[1];
            m.get(x).add(y);
            m.get(y).add(x);
        }
        
        for(int node: nodes) {
            if(!visited[node]) {
                Component component = new Component();
                go(node, component);
                components.add(component);
            }
        }
        
        
        int[] answer = {0, 0};
        for(Component component: components) {
            answer[0] += component.getNormalOrder();
            answer[1] += component.getReverseOrder();
        }
        
        return answer;
    }
    
    static class Component {
        int normalOdd;
        int normalEven;
        int reverseOdd;
        int reverseEven;
        
        int getNormalOrder() {
            return (normalOdd == 1 && normalEven == 0) || (normalOdd == 0 && normalEven == 1) ? 1 : 0;
        }
        
        int getReverseOrder() {
            return (reverseOdd == 1 && reverseEven == 0) || (reverseOdd == 0 && reverseEven == 1) ? 1 : 0;
        }
    }
}