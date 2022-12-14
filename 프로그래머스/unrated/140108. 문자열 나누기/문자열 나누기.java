class Solution {
    private int answer = 0;
    
    void go(String s) {
        char c = s.charAt(0);
        int c1 = 1, c2 = 0, i;
        
        for(i = 1; i < s.length(); i++) {
            if(s.charAt(i) == c)
                c1++;
            else
                c2++;
            
            if(c1 == c2)
                break;
        }
        
        if(c1 == c2 && i < s.length() - 1) {
            answer += 1;
            go(s.substring(i+1));
        }
    }
    
    public int solution(String s) {
        go(s);
        return answer + 1;
    }
}