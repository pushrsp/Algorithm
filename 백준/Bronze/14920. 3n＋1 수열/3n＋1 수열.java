import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());

        int ret = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n *= 3;
                n += 1;
            }
            ret++;
        }

        bw.write(String.valueOf(ret + 1) + '\n');

        br.close();
        bw.close();
    }
}