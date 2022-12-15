class Solution {
    private final int[][] DP = new int[100001][2];

        private void Set(int target) {
            if (DP[target - 60][0] == DP[target - 50][0]) {
                DP[target][0] = DP[target - 50][0] + 1;
                DP[target][1] = Math.max(DP[target - 60][1], DP[target - 50][1] + 1);
            } else if (DP[target - 60][0] < DP[target - 50][0]) {
                DP[target][0] = DP[target - 60][0] + 1;
                DP[target][1] = DP[target - 60][1];
            } else {
                DP[target][0] = DP[target - 50][0] + 1;
                DP[target][1] = DP[target - 50][1] + 1;
            }
        }

        public int[] solution(int target) {
            for (int i = 1; i <= target; i++) {
                if (i == 50 || i <= 20) {
                    DP[i][0] = 1;
                    DP[i][1] = 1;
                } else if (i <= 60 && i % 3 == 0) {
                    DP[i][0] = 1;
                    DP[i][1] = 0;
                } else if (i <= 40 && i % 2 == 0) {
                    DP[i][0] = 1;
                    DP[i][1] = 0;
                } else if (50 < i && i <= 70) {
                    DP[i][0] = 2;
                    DP[i][1] = 2;
                } else if (i < 70) {
                    if (i < 40) {
                        DP[i][0] = 2;
                        DP[i][1] = 2;
                    } else {
                        DP[i][0] = 2;
                        DP[i][1] = 1;
                    }
                } else {
                    Set(i);
                }
            }

            return new int[]{DP[target][0], DP[target][1]};
        }
}