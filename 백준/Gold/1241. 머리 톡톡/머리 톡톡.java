import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] A = new int[100_001];
    private static int[] B = new int[1_000_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(br.readLine());
            B[A[i]] += 1;
        }

        for (int i = 1; i <= N; i++) {
            int ret = 0;
            for (int j = 1; j * j <= A[i]; j++) {
                if (A[i] % j == 0) {
                    if (B[j] > 0) {
                        ret += (j == A[i]) ? B[j] - 1 : B[j];
                    }

                    int pair = A[i] / j;
                    if (pair != j && B[pair] > 0) {
                        ret += (pair == A[i]) ? B[pair] - 1 : B[pair];
                    }
                }
            }

            bw.write(String.valueOf(ret) + '\n');
        }

        br.close();
        bw.close();
    }
}