import java.util.*;

class Solution {
    private final int[][] DIST = {
                //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, *, #
                {0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1, 1}, // 0
                {4, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 5}, // 1
                {3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 4}, // 2
                {4, 2, 1, 0, 3, 2, 1, 4, 3, 2, 5, 3}, // 3
                {3, 1, 2, 3, 0, 1, 2, 1, 2, 3, 2, 4}, // 4
                {2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3}, // 5
                {3, 3, 2, 1, 2, 1, 0, 3, 2, 1, 4, 2}, // 6
                {2, 2, 3, 4, 1, 2, 3, 0, 1, 2, 1, 3}, // 7
                {1, 3, 2, 3, 2, 1, 2, 1, 0, 1, 2, 2}, // 8
                {2, 4, 3, 2, 3, 2, 1, 2, 1, 0, 3, 1}, // 9
                {1, 3, 4, 5, 2, 3, 4, 1, 2, 3, 0, 2}, // *
                {1, 5, 4, 3, 4, 3, 2, 3, 2, 1, 2, 0}, // #
        };
    
        public String solution(int[] numbers, String hand) {
            StringBuilder sb = new StringBuilder();

            int left = 10, right = 11;
            for (int number : numbers) {
                if (number == 1 || number == 4 || number == 7) {
                    sb.append("L");
                    left = number;
                } else if (number == 3 || number == 6 || number == 9) {
                    sb.append("R");
                    right = number;
                } else if(number == 2 || number == 5 || number == 8 || number == 0) {
                    int rightDist = DIST[right][number];
                    int leftDist = DIST[left][number];

                    if(rightDist < leftDist) {
                        right = number;
                        sb.append("R");
                    } else if(leftDist < rightDist) {
                        left = number;
                        sb.append("L");
                    } else {
                        if(hand.equals("right")) {
                            sb.append("R");
                            right = number;
                        } else {
                            sb.append("L");
                            left = number;
                        }
                    }
                }
            }


            return sb.toString();
        }
}