import java.util.*;

class Solution {
    private final int[][][] DP = new int[100001][10][10];
        private final int[][] Dist = new int[][]{
                {1, 7, 6, 7, 5, 4, 5, 3, 2, 3}, // 0
                {7, 1, 2, 4, 2, 3, 5, 4, 5, 6}, // 1
                {6, 2, 1, 2, 3, 2, 3, 5, 4, 5}, // 2
                {7, 4, 2, 1, 5, 3, 2, 6, 5, 4}, // 3
                {5, 2, 3, 5, 1, 2, 4, 2, 3, 5}, // 4
                {4, 3, 2, 3, 2, 1, 2, 3, 2, 3}, // 5
                {5, 5, 3, 2, 4, 2, 1, 5, 3, 2}, // 6
                {3, 4, 5, 6, 2, 3, 5, 1, 2, 4}, // 7
                {2, 5, 4, 5, 3, 2, 3, 2, 1, 2}, // 8
                {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}, // 9
        };
        private final HashMap<Character, Integer> CharToInt = new HashMap<>();
        private String Numbers;

        private void Set() {
            CharToInt.put('0', 0);
            CharToInt.put('1', 1);
            CharToInt.put('2', 2);
            CharToInt.put('3', 3);
            CharToInt.put('4', 4);
            CharToInt.put('5', 5);
            CharToInt.put('6', 6);
            CharToInt.put('7', 7);
            CharToInt.put('8', 8);
            CharToInt.put('9', 9);

            for (int i = 0; i < 100001; i++) {
                for (int j = 0; j < 10; j++) {
                    Arrays.fill(DP[i][j], -1);
                }
            }
        }

        private int go(int index, int left, int right) {
            if (index == Numbers.length())
                return 0;
            if (DP[index][left][right] != -1)
                return DP[index][left][right];

            int i = Numbers.charAt(index) - '0';
            DP[index][left][right] = Integer.MAX_VALUE;

            //같은 숫자 버튼 위에 동시에 엄지x
            if (right != i)
                DP[index][left][right] = Math.min(DP[index][left][right], go(index + 1, i, right) + Dist[left][i]);
            if (left != i)
                DP[index][left][right] = Math.min(DP[index][left][right], go(index + 1, left, i) + Dist[right][i]);

            return DP[index][left][right];
        }

        public int solution(String numbers) {
            Numbers = numbers;
            Set();
            return go(0, 4, 6);
        }
}