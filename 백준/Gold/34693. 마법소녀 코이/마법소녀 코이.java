import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T;
    private static long K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            K = Long.parseLong(st.nextToken());


            long t = K / 2;
            if (K % 2 == 1) {
                bw.write(String.valueOf(t + 3) + " - " + String.valueOf(t + 2) + " - 2\n");
            } else {
                bw.write(String.valueOf(t + 5) + " - " + String.valueOf(t + 4) + " - 3\n");
            }
        }

        br.close();
        bw.close();
    }
}