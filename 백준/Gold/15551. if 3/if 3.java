import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        String s1 = "A".repeat(N);
        String s2 = "A".repeat(N - 2) + "@`";

        bw.write(s1 + '\n');
        bw.write(s2 + '\n');

        br.close();
        bw.close();
    }
}