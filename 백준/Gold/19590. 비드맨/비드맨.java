import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        long sum = 0, max = 0;
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            long num = Long.parseLong(st.nextToken());
            sum += num;
            max = Math.max(max, num);
        }

        if (max >= (sum - max)) {
            bw.write(String.valueOf(max - (sum - max)) + '\n');
        } else {
            bw.write(String.valueOf(sum % 2) + '\n');
        }

        br.close();
        bw.close();
    }
}