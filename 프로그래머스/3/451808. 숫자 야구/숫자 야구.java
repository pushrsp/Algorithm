import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;

public class Solution {

    private int[] parse(int n1, int n2) {
        final String s1 = String.valueOf(n1);
        final String s2 = String.valueOf(n2);

        final int[] ret = new int[2];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == j) {
                        ret[0]++;
                    } else {
                        ret[1]++;
                    }
                    break;
                }
            }
        }
        return ret;
    }

    private boolean isValidCandidate(int number) {
        String strNumber = String.valueOf(number);
        for (int i = 0; i < strNumber.length(); i++) {
            for (int j = 0; j < strNumber.length(); j++) {
                if (i != j && strNumber.charAt(i) == strNumber.charAt(j)) {
                    return false;
                }
            }
        }
        return true;
    }

    private int getBestGuess(List<Integer> candidates) {
        if (candidates.size() <= 2) {
            return candidates.get(0);
        }

        int ret = candidates.get(0);
        int minMax = Integer.MAX_VALUE;
        for (int i = 0; i < candidates.size(); i++) {
            Map<String, Integer> map = new HashMap<>();
            for (Integer candidate : candidates) {
                int[] result = parse(candidates.get(i), candidate);
                String strResult = result[0] + "S " + result[1] + "B";
                if (map.containsKey(strResult)) {
                    map.replace(strResult, map.get(strResult) + 1);
                } else {
                    map.put(strResult, 1);
                }
            }

            int max = 0;
            for (Integer value : map.values()) {
                max = Math.max(max, value);
            }

            if (max < minMax) {
                minMax = max;
                ret = candidates.get(i);
            }
        }

        return ret;
    }

    public int solution(int n, Function<Integer, String> submit) {
        List<Integer> candidates = new ArrayList<>();
        for (int i = 1000; i <= 9999; i++) {
            if (isValidCandidate(i)) {
                candidates.add(i);
            }
        }

        while (candidates.size() > 1) {
            int bestGuess = getBestGuess(candidates);
            final String result = submit.apply(bestGuess);

            if ("4S 0B".equals(result)) {
                return bestGuess;
            }

            int strike = result.charAt(0) - '0';
            int ball = result.charAt(3) - '0';

            List<Integer> newCandidates = new ArrayList<>();
            for (Integer candidate : candidates) {
                int[] r = parse(bestGuess, candidate);
                if (r[0] == strike && r[1] == ball) {
                    newCandidates.add(candidate);
                }
            }

            candidates = newCandidates;
        }

        return candidates.get(0);
    }
}