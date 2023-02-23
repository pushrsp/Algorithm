import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static final Map<Long, Long> map = new HashMap<>();
    private static int N, K;
    private static long[] A, B;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = new long[N + 1];
        B = new long[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            A[i] = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            B[i] = Long.parseLong(st.nextToken());

        Map<Long, Long> map = new HashMap<>();
        map.put(0L, 1L);

        long s1 = 0, s2 = 0, ret = 0;

        for (int i = 1; i <= N; i++) {
            s1 += A[i];
            s2 += B[i];

            if (map.containsKey(s1 - s2))
                ret += map.get(s1 - s2);

            if (map.containsKey(s1 - s2))
                map.replace(s1 - s2, map.get(s1 - s2) + 1);
            else
                map.put(s1 - s2, 1L);
        }

        bw.write(ret + "\n");

        bw.close();
        br.close();
    }
}
