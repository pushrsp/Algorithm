import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static long A, B, X, Y;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());

        if (A > B) {
            long temp = A;
            A = B;
            B = temp;
        }

        st = new StringTokenizer(br.readLine());

        X = Math.abs(Long.parseLong(st.nextToken()));
        Y = Long.parseLong(st.nextToken());

        if (0 <= Y && Y < X) {
            long start = Math.floorDiv(A - Y, X) * X + Y;
            if (start < A) {
                start += X;
            }

            if (A <= start && start <= B) {
                if (A <= start + X && start + X <= B) {
                    bw.write("Unknwon Number\n");
                } else {
                    bw.write(String.valueOf(start) + '\n');
                }
            } else {
                bw.write("Unknwon Number\n");
            }
        } else {
            bw.write("Unknwon Number\n");
        }

        br.close();
        bw.close();
    }
}