import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static long N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Long.parseLong(st.nextToken());

        bw.write(String.valueOf((long) 2 * N) + '\n');

        br.close();
        bw.close();
    }
}