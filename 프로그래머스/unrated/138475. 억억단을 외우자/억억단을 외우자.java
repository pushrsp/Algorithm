class Solution {

    public int[] solution(int e, int[] starts) {
        int[] answer = new int[starts.length], numcnt = new int[5000001], numcntans = new int[5000001];

        for(int i = 2 ; i<=e ; i++){
            for(int j = 1 ; j<=(e/i) ; j++){
                numcnt[i*j]++;
            }
        }

        int max = 0, maxaddr = 0;

        for(int j = e ; j >=0 ; j--){
            maxaddr = max>numcnt[j]?maxaddr:j;
            max = max>numcnt[j]?max:numcnt[j];
            numcntans[j] = maxaddr;
        }


        for(int i = 0 ; i < starts.length ; i++){

            answer[i] = numcntans[starts[i]];

        }

        return answer;

    }
}