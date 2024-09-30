import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        String s1 = br.readLine();

        int[] a1 = new int[N];
        for (int n = 0; n < N; n++) {
            a1[n] = s1.charAt(n) - '0';
        }

        String s2 = br.readLine();

        int[] a2 = new int[N];
        for (int n = 0; n < N; n++) {
            a2[n] = s2.charAt(n) - '0';
        }

        int ret1 = 0;
        int[] t1 = Arrays.copyOf(a1, N);
        for (int n = 1; n < N; n++) {
            if (t1[n - 1] != a2[n - 1]) {
                ret1 += 1;
                t1[n - 1] ^= 1;
                t1[n] ^= 1;
                if (n + 1 < N) {
                    t1[n + 1] ^= 1;
                }
            }
        }

        for (int n = 0; n < N; n++) {
            if (t1[n] != a2[n]) {
                ret1 = Integer.MAX_VALUE;
                break;
            }
        }

        int ret2 = 1;
        int[] t2 = Arrays.copyOf(a1, N);
        t2[0] ^= 1;
        t2[1] ^= 1;
        for (int n = 1; n < N; n++) {
            if (t2[n - 1] != a2[n - 1]) {
                ret2 += 1;
                t2[n - 1] ^= 1;
                t2[n] ^= 1;
                if (n + 1 < N) {
                    t2[n + 1] ^= 1;
                }
            }
        }

        for (int n = 0; n < N; n++) {
            if (t2[n] != a2[n]) {
                ret2 = Integer.MAX_VALUE;
                break;
            }
        }

        int ret = Math.min(ret1, ret2);
        if (ret == Integer.MAX_VALUE) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(ret) + '\n');
        }

        br.close();
        bw.close();
    }
}