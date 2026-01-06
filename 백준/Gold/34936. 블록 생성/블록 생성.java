import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    private static int N, T, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.t == o2.t) {
                return Integer.compare(o1.f, o2.f);
            } else {
                return Integer.compare(o1.t, o2.t);
            }
        });


        TreeMap<Integer, PriorityQueue<Integer>> fee = new TreeMap<>();
        TreeMap<Integer, Integer> time = new TreeMap<>();

        long ret = 0;
        int op, t, f;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            op = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            if (op == 1) {
                f = Integer.parseInt(st.nextToken());
                if (!fee.containsKey(f)) {
                    fee.put(f, new PriorityQueue<>(Integer::compare));
                }

                fee.get(f).add(t);
                time.merge(t, 1, Integer::sum);
            } else {
                while (!time.isEmpty() && time.firstKey() < t - T) {
                    time.remove(time.firstKey());
                }

                int k = 0;
                while (!fee.isEmpty() && k < K) {
                    int lastKey = fee.lastKey();
                    int p = fee.get(lastKey).poll();
                    if (time.containsKey(p) && time.get(p) > 0) {
                        time.merge(p, -1, Integer::sum);
                        if (time.get(p) == 0) {
                            time.remove(p);
                        }
                        ret += lastKey;
                        k++;
                    }

                    if (fee.get(lastKey).isEmpty()) {
                        fee.remove(lastKey);
                    }
                }
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    static class Node {
        int t, f;

        Node(int t, int f) {
            this.t = t;
            this.f = f;
        }
    }
}