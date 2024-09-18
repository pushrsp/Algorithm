import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] a1, a2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        a1 = new int[N];
        a2 = new int[N];

        String s1 = br.readLine();
        for (int i = 0; i < s1.length(); i++) {
            a1[i] = s1.charAt(i) == '0' ? 0 : 1;
        }

        String s2 = br.readLine();
        for (int i = 0; i < s2.length(); i++) {
            a2[i] = s2.charAt(i) == '0' ? 0 : 1;
        }

        int[] temp1 = Arrays.copyOf(a1, a1.length);
        temp1[0] = (temp1[0] + 1) % 2;
        temp1[1] = (temp1[1] + 1) % 2;

        int ret1 = 1;
        for (int i = 1; i < N; i++) {
            if (temp1[i - 1] != a2[i - 1]) {
                temp1[i - 1] = (temp1[i - 1] + 1) % 2;
                temp1[i] = (temp1[i] + 1) % 2;

                if (i + 1 < N) {
                    temp1[i + 1] = (temp1[i + 1] + 1) % 2;
                }
                ret1 += 1;
            }
        }

        for (int n = 0; n < N; n++) {
            if (temp1[n] != a2[n]) {
                ret1 = Integer.MAX_VALUE;
                break;
            }
        }

        int[] temp2 = Arrays.copyOf(a1, a1.length);
        int ret2 = 0;
        for (int i = 1; i < N; i++) {
            if (temp2[i - 1] != a2[i - 1]) {
                temp2[i - 1] = (temp2[i - 1] + 1) % 2;
                temp2[i] = (temp2[i] + 1) % 2;

                if (i + 1 < N) {
                    temp2[i + 1] = (temp2[i + 1] + 1) % 2;
                }
                ret2 += 1;
            }
        }

        for (int n = 0; n < N; n++) {
            if (temp2[n] != a2[n]) {
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