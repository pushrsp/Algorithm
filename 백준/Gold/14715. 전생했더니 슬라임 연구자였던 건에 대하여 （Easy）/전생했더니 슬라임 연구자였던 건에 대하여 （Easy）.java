import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());

        int ret = 1;
        while (true) {
            boolean isPrime = true;
            for (int k = 2; k < K; k++) {
                if (K % k == 0) {
                    isPrime = false;
                    K /= k;
                    ret++;
                    break;
                }
            }

            if (isPrime) {
                break;
            }
        }
        
        bw.write(String.valueOf((int) Math.ceil(Math.log10(ret) / Math.log10(2))) + '\n');
        br.close();
        bw.close();
    }
}