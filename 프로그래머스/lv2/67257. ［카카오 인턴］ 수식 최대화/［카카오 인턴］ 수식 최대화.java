import java.util.*;
import java.lang.*;

public class Solution {
    private static final boolean[] VISITED = {false, false, false};
    private final List<Character> operators = new ArrayList<>();
    private final List<Character> uniqueOperators = new ArrayList<>();
    private final List<Long> numbers = new ArrayList<>();
    private final List<Character> tempOpers = new ArrayList<>();
    private long Answer = Long.MIN_VALUE;

    private Long calc(Long n1, Long n2, Character op) {
        switch (op) {
            case '+':
                return n1 + n2;
            case '-':
                return n1 - n2;
            default:
                return n1 * n2;
        }
    }

    private Long go() {
        List<Long> nums = new ArrayList<>(numbers);
        List<Character> ops = new ArrayList<>(operators);

        for (Character op : tempOpers) {
            for (int i = 0; i < ops.size(); i++) {
                if(ops.get(i) == op) {
                    nums.set(i, calc(nums.get(i), nums.get(i + 1), op));
                    nums.remove(i + 1);
                    ops.remove(i);
                    i--;
                }
            }
        }

        return Math.abs(nums.get(0));
    }

    private void perm(int count) {
        if(count == uniqueOperators.size()) {
            Long result = go();

            if(result > Answer)
                Answer = result;

            return;
        }

        for (int i = 0; i < uniqueOperators.size(); i++) {
            if(VISITED[i])
                continue;

            VISITED[i] = true;
            tempOpers.add(uniqueOperators.get(i));

            perm(count + 1);

            tempOpers.remove(tempOpers.size() - 1);
            VISITED[i] = false;
        }
    }

    public long solution(String expression) {
        String temp = "";
        Set<Character> unique = new HashSet<>();
        for (int i = 0; i < expression.length(); i++) {
            if(expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*') {
                unique.add(expression.charAt(i));
                numbers.add(Long.parseLong(temp));
                temp = "";
                operators.add(expression.charAt(i));
            } else {
                temp += expression.charAt(i);
            }
        }

        if(!temp.isEmpty())
            numbers.add(Long.parseLong(temp));

        uniqueOperators.addAll(unique);

        perm(0);

        return Answer;
    }
}