import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        long min = Long.MIN_VALUE;
        boolean ret = true;
        for (int i = 0; i < N; i++) {
            long n = Long.parseLong(st.nextToken());
            if (n <= min) {
                ret = false;
            }
            min = n;
        }

        if (ret) {
            bw.write(String.valueOf(1) + '\n');
        } else {
            bw.write(String.valueOf(0) + '\n');
        }

        br.close();
        bw.close();
    }
}