import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N;
    private static List<Pair> pairs = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        pairs.sort((o1, o2) -> {
            if(o1.sum == o2.sum) {
                return -Long.compare(o1.a, o2.a);
            }
            return -Long.compare(o1.sum, o2.sum);
        });

        List<Long> temp = new ArrayList<>();
        temp.add(0L);

        for (Pair pair : pairs) {
            temp.add(temp.get(temp.size() - 1) + pair.a);
            temp.add(temp.get(temp.size() - 1) - pair.b);
        }

        long offset = 0;
        for (Long n : temp) {
            offset = Math.min(offset, n);
        }

        long ret = 0;
        for (int i = 1; i < temp.size(); i += 2) {
            ret += temp.get(i) - offset;
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            pairs.add(new Pair(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken())));
        }
    }

    static class Pair {
        public long a, b;
        public long sum;

        public Pair(long a, long b) {
            this.a = a;
            this.b = b;
            this.sum = a - b;
        }
    }
}
