import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Integer.parseInt(st.nextToken());

        if (A == 1) {
            bw.write("goose\n");
        } else {
            int a = A - 1;
            if (a % 4 == 0 || a % 4 == 3) {
                bw.write("goose\n");
            } else {
                bw.write("duck\n");
            }
        }

        br.close();
        bw.close();
    }
}