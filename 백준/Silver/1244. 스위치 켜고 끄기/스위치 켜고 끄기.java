import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            A[n] = Integer.parseInt(st.nextToken());
        }

        M = Integer.parseInt(br.readLine());

        int g, n;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            g = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            if (g == 1) {
                for (int i = n; i <= N; i += n) {
                    A[i] ^= 1;
                }
            } else {
                A[n] ^= 1;
                int left = n - 1, right = n + 1;
                while (1 <= left && right <= N) {
                    if (A[left] == A[right]) {
                        A[left--] ^= 1;
                        A[right++] ^= 1;
                    } else {
                        break;
                    }
                }
            }
        }

        int i = 0;
        while (i < N) {
            bw.write(String.valueOf(A[i + 1]) + ' ');
            i++;
            if (i % 20 == 0) {
                bw.write('\n');
            }
        }

        br.close();
        bw.close();
    }
}