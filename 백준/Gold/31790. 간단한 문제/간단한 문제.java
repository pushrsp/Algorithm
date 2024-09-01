import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, P;
    private static int[] B;
    private static int[] R;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        B = new int[N + 1];

        st = new StringTokenizer(br.readLine());

        boolean valid = true;
        for (int n = 1; n <= N; n++) {
            B[n] = Integer.parseInt(st.nextToken());

            if (!(B[n] - B[n - 1] == 1 || B[n] - B[n - 1] == 0)) {
                valid = false;
            }

            if (!(n <= B[n] * P)) {
                valid = false;
            }
        }

        int a = N / P;
        if (N % P != 0) {
            a += 1;
        }
        
        if (!valid || B[1] != 1 || B[N] != a) {
            bw.write("NO\n");
            br.close();
            bw.close();
            return;
        }

//        R = new int[P];
//
//        int r = 0;
//        for (int n = 1; n <= N; n++) {
//            if (B[n - 1] < B[n]) {
//                R[r] += 1;
//            } else if (B[n - 1] == B[n]) {
//                if (R[(r + 1) % P] < B[n]) {
//                    r = (r + 1) % P;
//                    R[r] += 1;
//                } else {
//                    boolean find = false;
//                    for (int p = 0; p < P; p++) {
//                        if (R[p] < B[n]) {
//                            R[p] += 1;
//                            r = p;
//                            find = true;
//                            break;
//                        }
//                    }
//
//                    if (!find) {
//                        bw.write("NO\n");
//                        br.close();
//                        bw.close();
//                        return;
//                    }
//                }
//            } else {
//                bw.write("NO\n");
//                br.close();
//                bw.close();
//                return;
//            }
//        }

        bw.write("YES\n");

        br.close();
        bw.close();
    }
}
