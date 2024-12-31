import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    private static int N, K;
    private static Queue<Integer>[] Q = new Queue[500001];

    static class Pair {
        int product, remain, next;

        Pair(int product, int remain, int next) {
            this.product = product;
            this.remain = remain;
            this.next = next;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        List<Integer> list = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();

        st = new StringTokenizer(br.readLine());
        int num;
        for (int k = 0; k < K; k++) {
            num = Integer.parseInt(st.nextToken());
            list.add(num);
            if (Q[num] == null) {
                Q[num] = new LinkedList<>();
            }

            Q[num].add(k);
            if (map.containsKey(num)) {
                map.replace(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }

        Set<Integer> set = new HashSet<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.next == o2.next) {
                return Integer.compare(o1.remain, o2.remain);
            }
            return -Integer.compare(o1.next, o2.next);
        });

        int ret = 0;
        for (Integer product : list) {
            int remain = map.get(product) - 1;
            if (remain == 0) {
                map.remove(product);
            } else {
                map.replace(product, remain);
            }

            Q[product].poll();
            if (set.contains(product)) {
                pq.add(new Pair(product, remain, Q[product].isEmpty() ? Integer.MAX_VALUE : Q[product].peek()));
                continue;
            }

            if (set.size() < N) {
                set.add(product);
                pq.add(new Pair(product, remain, Q[product].isEmpty() ? Integer.MAX_VALUE : Q[product].peek()));
            } else {
                ret++;
                Pair pair = pq.poll();
                set.remove(pair.product);
                set.add(product);
                pq.add(new Pair(product, remain, Q[product].isEmpty() ? Integer.MAX_VALUE : Q[product].peek()));
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}