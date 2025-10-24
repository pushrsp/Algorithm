import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static int N, D, K, C;
    private static int[] A = new int[30_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
        }

        int ret = 0;
        Set<Integer> sushi = new HashSet<>();
        for (int i = 0; i < N; i++) {
            int count = 0;
            while (count < K) {
                sushi.add(A[(i + count) % N]);
                count++;
            }
            sushi.add(C);
            ret = Math.max(ret, sushi.size());
            sushi.clear();
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}