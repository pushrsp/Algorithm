import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        if (N == M) {
            int len = (N - 2) * (N - 2);
            bw.write(String.valueOf(len + 1) + '\n');
        } else {
            int len = Math.min(N, M) - 1;
            bw.write(String.valueOf(len * len) + '\n');
        }

        br.close();
        bw.close();
    }
}