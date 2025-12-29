import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        long ret = N + K - 1;
        for (int len = 2; len <= N; len++) {
            long max = K + (N - len);
            int medianIndex = (len + 1) / 2;
            long median = max - len + medianIndex;
            ret = Math.max(ret, median * len);
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}