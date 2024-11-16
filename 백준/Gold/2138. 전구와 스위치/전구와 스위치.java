import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] A, B, C;

    private static boolean isSame(int[] a, int[] b) {
        for (int n = 0; n < N; n++) {
            if (a[n] != b[n]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        String s1 = br.readLine();

        A = new int[N];
        B = new int[N];
        for (int n = 0; n < N; n++) {
            A[n] = s1.charAt(n) - '0';
            B[n] = s1.charAt(n) - '0';
        }

        String s2 = br.readLine();
        C = new int[N];
        for (int n = 0; n < N; n++) {
            C[n] = s2.charAt(n) - '0';
        }

        int ret = 0;
        for (int n = 1; n < N; n++) {
            if (A[n - 1] != C[n - 1]) {
                A[n - 1] = (A[n - 1] + 1) % 2;
                A[n] = (A[n] + 1) % 2;
                if (n + 1 < N) {
                    A[n + 1] = (A[n + 1] + 1) % 2;
                }
                ret++;
            }
        }

        int ret2 = 1;
        B[0] = (B[0] + 1) % 2;
        B[1] = (B[1] + 1) % 2;
        for (int n = 1; n < N; n++) {
            if (B[n - 1] != C[n - 1]) {
                B[n - 1] = (B[n - 1] + 1) % 2;
                B[n] = (B[n] + 1) % 2;
                if (n + 1 < N) {
                    B[n + 1] = (B[n + 1] + 1) % 2;
                }
                ret2++;
            }
        }

        boolean isSame1 = isSame(A, C);
        boolean isSame2 = isSame(B, C);

        if (!isSame1 && !isSame2) {
            bw.write(String.valueOf(-1) + '\n');
        } else if (isSame1 && isSame2) {
            bw.write(String.valueOf(Math.min(ret, ret2)) + '\n');
        } else if (isSame1) {
            bw.write(String.valueOf(ret) + '\n');
        } else {
            bw.write(String.valueOf(ret2) + '\n');
        }

        br.close();
        bw.close();
    }
}