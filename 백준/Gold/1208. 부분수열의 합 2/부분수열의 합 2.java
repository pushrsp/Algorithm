import java.io.*;
import java.util.*;

public class Main {
    private static int N, S;
    private static int[] Arr;
    private static Map<Long, Long> map1 = new HashMap<>();
    private static Map<Long, Long> map2 = new HashMap<>();

    public static void go(int start, int end, Long sum, Map<Long, Long> map) {
        if(start == end + 1) {
            if(!map.containsKey(sum)) {
                map.put(sum, 1L);
            } else {
                Long count = map.get(sum);
                map.replace(sum, count + 1);
            }

            return;
        }

        go(start + 1, end, sum + Arr[start], map);
        go(start + 1, end, sum, map);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        Arr = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            Arr[i] = Integer.parseInt(st.nextToken());

        int half = N / 2;
        go(1, half, 0L, map1);
        go(half + 1, N, 0L, map2);

        Long ret = 0L;
        for (Long key : map1.keySet()) {
            if(map2.containsKey(S - key))
                ret += map1.get(key) * map2.get(S - key);
        }

        if(S == 0)
            bw.write(String.valueOf(ret - 1));
        else
            bw.write(String.valueOf(ret));

        bw.close();
        br.close();
    }
}
