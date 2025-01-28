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

        boolean isValid = true;
        if (Y < 0 || Y >= X) {
            isValid = false;
        }

        long first = (A / X) * X + Y;
        if ((first - A) >= X) {
            first -= X;
        } else if (A - first > 0) {
            first += X;
        }

        if (!isValid) {
            bw.write("Unknwon Number\n");
        } else if (B >= first) {
            if (B >= first + X) {
                bw.write("Unknwon Number\n");
            } else {
                bw.write(String.valueOf(first) + '\n');
            }
        } else {
            bw.write("Unknwon Number\n");
        }

        br.close();
        bw.close();
    }
}