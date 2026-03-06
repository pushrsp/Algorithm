import java.util.*;

class Solution {

    public long solution(long dist_limit, long split_limit) {
        if (dist_limit == 0) {
            return 1;
        }

        // BFS로 h(remaining, sLimit) 계산
        // h = "분배노드 remaining개로 노드 1개에서 만들 수 있는 최대 리프"
        //
        // 노드 1개에서:
        //   리프로 남기기 → 1
        //   b로 분배 → 자식 b개, 남은 분배 (remaining-1)을 b개에 균등분배
        //     각 자식에게 q 또는 q+1개씩 (q = (remaining-1)/b)
        //     → rem * h(q+1, sLimit/b) + (b-rem) * h(q, sLimit/b)

        // 1단계: 필요한 상태 수집 (스택으로 의존관계 탐색)
        Map<Long, long[]> stateMap = new LinkedHashMap<>(); // key -> {remaining, sLimit}
        Deque<long[]> stack = new ArrayDeque<>();
        stack.push(new long[]{dist_limit, split_limit});

        while (!stack.isEmpty()) {
            long[] cur = stack.pop();
            long rem = cur[0], sl = cur[1];
            long key = rem * 1_000_000_001L + sl;
            if (stateMap.containsKey(key)) continue;
            stateMap.put(key, new long[]{rem, sl});

            if (rem == 0 || sl < 2) continue;
            for (int b = 2; b <= 3; b++) {
                if (sl < b) continue;
                long r = rem - 1;
                long ns = sl / b;
                long q = r / b;
                long rest = r % b;
                stack.push(new long[]{q, ns});
                if (rest > 0) {
                    stack.push(new long[]{q + 1, ns});
                }
            }
        }

        // 2단계: sLimit 오름차순 정렬 (의존 대상 먼저 계산)
        List<long[]> order = new ArrayList<>(stateMap.values());
        order.sort((a, b) -> {
            if (a[1] != b[1]) return Long.compare(a[1], b[1]);
            return Long.compare(a[0], b[0]);
        });

        // 3단계: BFS 순서로 dp 테이블 채우기
        Map<Long, Long> dp = new HashMap<>();
        for (long[] pair : order) {
            long rem = pair[0], sl = pair[1];
            long key = rem * 1_000_000_001L + sl;

            if (rem == 0 || sl < 2) {
                dp.put(key, 1L);
                continue;
            }

            long best = 1;
            for (int b = 2; b <= 3; b++) {
                if (sl < b) continue;
                long r = rem - 1;
                long ns = sl / b;
                long q = r / b;
                long rest = r % b;
                long v1 = dp.getOrDefault((q + 1) * 1_000_000_001L + ns, 1L);
                long v2 = dp.getOrDefault(q * 1_000_000_001L + ns, 1L);
                long val = rest * v1 + (b - rest) * v2;
                best = Math.max(best, val);
            }
            dp.put(key, best);
        }

        return dp.getOrDefault(dist_limit * 1_000_000_001L + split_limit, 1L);
    }
}