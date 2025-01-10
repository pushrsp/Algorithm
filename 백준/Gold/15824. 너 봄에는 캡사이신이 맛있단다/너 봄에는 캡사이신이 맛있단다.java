import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private final static int MOD = 1_000_000_007;
    private static int N;
    private static int[] S = new int[300001];

    private static long pow(int b, int x) {
        if (x == 0) {
            return 1L;
        }

        long half = pow(b, x / 2);
        return x % 2 == 0 ? half * half % MOD : half * half * b % MOD;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(list);

        long ret = 0;
        for (int i = 0; i < N; i++) {
            ret += list.get(i) * pow(2, i);
            ret -= list.get(i) * pow(2, N - i - 1);
            ret %= MOD;
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}