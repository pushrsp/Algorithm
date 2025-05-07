import java.util.*;

class Solution {
    public int solution(int n, int w, int num) {
        final int maxFloor = (n - 1) / w;
        
        final int targetFloor = (num - 1) / w;
        int targetIndex = (num - 1) % w;
        if(targetFloor % 2 == 1) {
            targetIndex = w - 1 - targetIndex;
        }
        
        int[] arr = new int[w];
        Arrays.fill(arr, -1);
        
        for(int i = 0; i < w; i++) {
            arr[maxFloor % 2 == 0 ? i : w - 1 - i] = (w * maxFloor) + i;
        }
        
        int answer = maxFloor - targetFloor;
        if(arr[targetIndex] > n - 1) {
            answer--;
        }
        
        return answer + 1;
    }
}