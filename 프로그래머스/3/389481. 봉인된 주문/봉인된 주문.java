import java.util.*;

public class Solution {

    public String solution(long n, String[] bans) {
        Set<String> banSet = new HashSet<>(Arrays.asList(bans));
        Map<Integer, Long> map = new HashMap<>();
        for (String ban : bans) {
            map.put(ban.length(), map.getOrDefault(ban.length(), 0L) + 1);
        }

        long count = 0;
        for (int i = 1; i <= 11; i++) {
            long total = pow26(i);
            if (count + (total - map.getOrDefault(i, 0L)) >= n) {
                long target = n - count;
                return findNthString(target, i, banSet);
            }
            count += total - map.getOrDefault(i, 0L);
        }

        return "";
    }

    private String findNthString(long n, int length, Set<String> banSet) {
        StringBuilder sb = new StringBuilder();
        long remaining = n;
        for (int i = 0; i < length; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                String prefix = sb.toString() + c;

                long validCount;
                if (i == length - 1) {
                    validCount = banSet.contains(prefix) ? 0 : 1;
                } else {
                    long candidatesCount = pow26(length - i - 1);
                    long bannedCount = countBannedWithPrefix(prefix, length, banSet);
                    validCount = candidatesCount - bannedCount;
                }

                if (remaining <= validCount) {
                    sb.append(c);
                    break;
                } else {
                    remaining -= validCount;
                }
            }
        }
        return sb.toString();
    }

    private long countBannedWithPrefix(String prefix, int totalLength, Set<String> banSet) {
        long count = 0;
        for (String ban : banSet) {
            if (ban.length() == totalLength && ban.startsWith(prefix)) {
                count++;
            }
        }

        return count;
    }

    private long pow26(int n) {
        long ret = 1;
        for (int i = 0; i < n; i++) {
            ret *= 26;
        }
        return ret;
    }
}
