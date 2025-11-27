import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static long K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        PriorityQueue<Long> pq = new PriorityQueue<>(Long::compare);
        for (int i = 0; i < M; i++) {
            pq.add(0L);
        }

        st = new StringTokenizer(br.readLine());

        long a;
        for (int i = 0; i < N; i++) {
            a = Integer.parseInt(st.nextToken());
            pq.add(pq.poll() + a);
        }

        if (pq.peek() > K) {
            bw.write("GO\n");
        } else {
            bw.write("WAIT\n");
        }

        br.close();
        bw.close();
    }
}