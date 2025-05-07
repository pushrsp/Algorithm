import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int[] arr = new int[51];
        
        int answer = 0;
        for(int i = 0; i < 24; i++) {
            int requiredServerCount = players[i] / m;
            if(arr[i] < requiredServerCount) {
                answer += requiredServerCount - arr[i];
                int temp = arr[i];
                
                for(int j = i; j < i + k; j++) {
                    arr[j] += requiredServerCount - temp;
                }
            }
        }
        
        return answer;
    }
}