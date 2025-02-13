import java.util.*;

class Solution {
    private boolean isWeekend(int day) {
        return day == 5 || day == 6;
    }
    
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int n = schedules.length;
        startday--;
        
        int answer = 0;
        for(int i = 0; i < n; i++) {
            int s = schedules[i];
            int hour = s / 100;
            int min = s - (hour * 100);
            
            if(min + 10 >= 60) {
                hour += 1;
            }
            
            min = (min + 10) % 60;
            int ss = hour * 100 + min;
            
            boolean success = true;
            for(int j = 0; j < 7; j++) {
                if(!isWeekend((j + startday) % 7)) {
                    if(timelogs[i][j] > ss) {
                        success = false;
                        break;
                    }
                }
            }
            
            answer += success ? 1 : 0;
        }
        
        return answer;
    }
}