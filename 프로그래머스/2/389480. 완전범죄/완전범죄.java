import java.util.*;

class Solution {

    private static int[][] DP = new int[51][130];
    private static int MAX = 9_999_999;

    public int solution(int[][] info, int n, int m) {
        for (int i = 0; i <= info.length; i++) {
            Arrays.fill(DP[i], MAX);
        }

        DP[0][0] = 0;
        for (int i = 1; i <= info.length; i++) {
            int a = info[i - 1][0], b = info[i - 1][1];
            for (int j = 0; j < m; j++) {
                DP[i][j] = Math.min(DP[i][j], DP[i - 1][j] + a);
                if (j + b < m) {
                    DP[i][j + b] = Math.min(DP[i][j + b], DP[i - 1][j]);
                }
            }
        }
        int answer = MAX;
        for (int i = 0; i < m; i++) {
            answer = Math.min(answer, DP[info.length][i]);
        }
        return answer >= n ? -1 : answer;
    }
}
