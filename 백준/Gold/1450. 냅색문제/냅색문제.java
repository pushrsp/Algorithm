import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static final long[][] DP = new long[31][31];
    private static Integer N;
    private static long C;
    private static long[] Arr;
    private static List<Long> L1, L2;

    private static void go1(int i, long sum) {
        if (sum > C)
            return;
        if (i == N / 2) {
            L1.add(sum);
            return;
        }

        go1(i + 1, sum + Arr[i]);
        go1(i + 1, sum);
    }

    private static void go2(int i, long sum) {
        if (sum > C)
            return;
        if (i == N) {
            L2.add(sum);
            return;
        }

        go2(i + 1, sum + Arr[i]);
        go2(i + 1, sum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        L1 = new ArrayList<>();
        L2 = new ArrayList<>();

        N = Integer.parseInt(st.nextToken());
        C = Long.parseLong(st.nextToken());

        Arr = new long[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            Arr[i] = Long.parseLong(st.nextToken());

        go1(0, 0);
        go2(N / 2, 0);

        Collections.sort(L2);

        int ret = 0;
        for (Long aSum : L1) {
            int left = 0, right = L2.size() - 1, mid, index = -1;

            while (left <= right) {
                mid = (left + right) / 2;

                if (L2.get(mid) + aSum <= C) {
                    index = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            ret += index + 1;
        }

        bw.write(String.valueOf(ret));

        bw.close();
        br.close();
    }
}
