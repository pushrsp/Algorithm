import java.io.*;
import java.util.*;

public class Main {

    private static int N;

    static void removeOne(TreeMap<Long, Integer> map, long key) {
        int cnt = map.get(key);
        if (cnt == 1) {
            map.remove(key);
        } else {
            map.put(key, cnt - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        TreeMap<Long, Integer> original = new TreeMap<>();

        long num = 0;
        for (int i = 0; i < 2 * N; i++) {
            num = Long.parseLong(st.nextToken());
            original.put(num, original.getOrDefault(num, 0) + 1);
        }

        if (N == 1) {
            bw.write(String.valueOf(num) + '\n');
            br.close();
            bw.close();
            return;
        }

        Queue<Long> q = new LinkedList<>();
        for (Map.Entry<Long, Integer> entry : original.entrySet()) {
            if (entry.getValue() >= 2) {
                q.add(entry.getKey());
            }
        }

        while (!q.isEmpty()) {
            long candidate = q.poll();

            TreeMap<Long, Integer> copy = new TreeMap<>(original);
            removeOne(copy, candidate);
            removeOne(copy, candidate);

            long[] p = new long[N];
            p[N - 1] = candidate;

            p[0] = copy.firstKey();
            removeOne(copy, p[0]);

            boolean success = true;
            for (int i = 0; i < N - 1; i++) {
                long y = candidate - p[i];
                if (!copy.containsKey(y)) {
                    success = false;
                    break;
                }
                removeOne(copy, y);
                if (i + 1 < N - 1) {
                    if (copy.isEmpty()) {
                        success = false;
                        break;
                    }

                    p[i + 1] = copy.firstKey();
                    removeOne(copy, p[i + 1]);
                }
            }

            if (!copy.isEmpty()) {
                success = false;
            }

            if (success) {
                bw.write(String.valueOf(p[0]) + ' ');
                for (int i = 1; i < N - 1; i++) {
                    bw.write(String.valueOf(p[i] - p[i - 1]) + ' ');
                }
                bw.write(String.valueOf(p[N - 1] - p[N - 2]) + '\n');
                break;
            }
        }

        br.close();
        bw.close();
    }
}