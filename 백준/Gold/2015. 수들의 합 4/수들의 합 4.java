import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static final Map<Long, Long> map = new HashMap<>();
    private static int N, K;
    private static long[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new long[N + 1];

        long ret = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken()) + arr[i - 1];
            if (arr[i] == K)
                ret += 1;

            if (map.containsKey(arr[i] - K))
                ret += map.get(arr[i] - K);

            if (!map.containsKey(arr[i]))
                map.put(arr[i], 1L);
            else
                map.replace(arr[i], map.get(arr[i]) + 1);
        }

        bw.write(ret + "\n");

        bw.close();
        br.close();
    }
}
