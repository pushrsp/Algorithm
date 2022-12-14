import java.util.Arrays;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        int[] visited = new int[26];
        
        Arrays.fill(visited, -1);
        
        for(int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            
            if(visited[index] == -1) {
                visited[index] = i;
                answer[i] = -1;
                continue;
            }
            
            answer[i] = i - visited[index];
            visited[index] = i;
        }
        return answer;
    }
}