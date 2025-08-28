import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int N, A, B;

    private static boolean[] PRIME = new boolean[200_001];
    private static int[] T1 = new int[200_001];
    private static int[] T2 = new int[200_001];
    private static int[] DP = new int[200_001];

    private static int getScore(int sum) {
        return PRIME[sum] ? B : A;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            T1[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            T2[i] = Integer.parseInt(st.nextToken());
        }

        PRIME[0] = PRIME[1] = true;

        for (int i = 2; i * i <= 200_000; i++) {
            if (!PRIME[i]) {
                for (int j = i * i; j <= 200_000; j += i) PRIME[j] = true;
            }
        }

        DP[1] = getScore(T1[1] + T2[1]);

        for (int i = 2; i <= N; i++) {
            DP[i] = DP[i - 1] + getScore(T1[i] + T2[i]);
            DP[i] = Math.max(DP[i], DP[i - 2] + getScore(T1[i - 1] + T1[i]) + getScore(T2[i - 1] + T2[i]));
        }

        bw.write(String.valueOf(DP[N]) + '\n');

        br.close();
        bw.close();
    }
}