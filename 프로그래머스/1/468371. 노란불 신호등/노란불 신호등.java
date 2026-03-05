import java.util.*;

class Solution {
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    public int solution(int[][] signals) {
        int n = signals.length;
        int maxDist = 1;
        for (int[] signal : signals) {
            maxDist = lcm(maxDist, signal[0] + signal[1] + signal[2]);
        }

        for (int t = 1; t <= maxDist; t++) {
            boolean allYellow = true;
            for (int[] signal : signals) {
                int period = signal[0] + signal[1] + signal[2];
                int pos = (t - 1) % period;
                if (pos < signal[0] || pos >= signal[0] + signal[1]) {
                    allYellow = false;
                    break;
                }
            }
            if (allYellow) return t;
        }

        return -1;
    }
}