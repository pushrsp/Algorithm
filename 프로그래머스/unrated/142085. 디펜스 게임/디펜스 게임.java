import java.util.PriorityQueue;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        if(k == enemy.length)
            return k;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1, i2) -> -(i1 - i2));
        int num = n;
        int i;
        int count = 0;
        
        for(i = 0; i < enemy.length; i++) {
            int now = enemy[i];
            pq.add(now);
            num -= now;
            
            if(num < 0) {
                if(count < k) {
                    num += pq.poll();
                    count++;
                } else {
                    break;
                }
            }
        }
        
        return i;
    }
}