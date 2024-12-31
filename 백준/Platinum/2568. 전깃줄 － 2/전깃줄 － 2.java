import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    private static int N;
    private static int[] INDEX = new int[100001];

    static class Pair {
        int a, b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    private static int lowerBound(List<Integer> sorted, int target) {
        if (sorted.isEmpty()) {
            return 0;
        }

        int left = 0, right = sorted.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (sorted.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        List<Pair> pairs = new ArrayList<>();

        int a, b;
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            pairs.add(new Pair(a, b));
        }

        pairs.sort(Comparator.comparingInt(o -> o.a));

        List<Integer> candidates = new ArrayList<>();
        for (Pair pair : pairs) {
            candidates.add(pair.b);
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            b = candidates.get(i);
            if (ans.isEmpty()) {
                INDEX[i] = 0;
                ans.add(b);
            } else {
                int index = lowerBound(ans, b);
                INDEX[i] = index;
                if (index == ans.size()) {
                    ans.add(b);
                } else {
                    ans.set(index, b);
                }
            }
        }

        bw.write(String.valueOf(pairs.size() - ans.size()) + '\n');

        Set<Integer> visited = new HashSet<>();
        int maxIndex = ans.size() - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (INDEX[i] == maxIndex) {
                maxIndex--;
                visited.add(candidates.get(i));
            }
        }

        List<Integer> ret = new ArrayList<>();
        for (Pair pair : pairs) {
            if (!visited.contains(pair.b)) {
                ret.add(pair.a);
            }
        }

        Collections.sort(ret);

        for (Integer i : ret) {
            bw.write(String.valueOf(i) + '\n');
        }

        br.close();
        bw.close();
    }
}