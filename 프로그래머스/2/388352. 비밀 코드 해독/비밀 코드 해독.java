import java.util.*;

class Solution {
    
    private List<Set<Integer>> candidates = new ArrayList<>();
    private List<Integer> candidate = new ArrayList<>();
    private List<Integer> numbers = new ArrayList<>();
    
    private void go(int start, int count) {
        if(numbers.size() - start < 5) {
            return;
        }
        
        if(count == 5) {
            Set<Integer> s = new HashSet<>();
            for(Integer number: candidate) {
                s.add(number);
            }
            
            if(s.size() == 5) {
                candidates.add(s);
            }
            
            candidate.remove(candidate.size() - 1);
            return;
        }
        
        for(int i = start; i < numbers.size(); i++) {
            candidate.add(i);
            go(i + 1, count + 1);
        }
    }
    
    private void go() {
        for(int a = 0; a < numbers.size(); a++) {
            for(int b = a + 1; b < numbers.size(); b++) {
                for(int c = b + 1; c < numbers.size(); c++) {
                    for(int d = c + 1; d < numbers.size(); d++) {
                        for(int e = d + 1; e < numbers.size(); e++) {
                            Set<Integer> s = new HashSet<>();
                            s.add(numbers.get(a));
                            s.add(numbers.get(b));
                            s.add(numbers.get(c));
                            s.add(numbers.get(d));
                            s.add(numbers.get(e));
                            
                            candidates.add(s);
                        }
                    }
                }
            }
        }
    }
    
    private boolean isSameArray(int[] a, int[] b, int len) {
        for(int i = 0; i < len; i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    
    public int solution(int n, int[][] q, int[] ans) {
        for(int i = 1; i <= n; i++) {
            numbers.add(i);
        }
        
        go();
        
        int answer = 0;
        
        int m = ans.length;
        int[] temp = new int[m];
        for(Set<Integer> candidate: candidates) {
            Arrays.fill(temp, 0);
            
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < 5; j++) {
                    if(candidate.contains(q[i][j])) {
                        temp[i]++;
                    }
                }
            }
            
            if(isSameArray(temp, ans, m)) {
                answer++;
            }
        }
        
        
        return answer;
    }
}