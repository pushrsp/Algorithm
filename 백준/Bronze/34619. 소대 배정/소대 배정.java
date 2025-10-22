import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a, b, n, k;
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        k--;
        int i = k / (b * n);
        int j = k / n;
        j %= b;

        bw.write(String.valueOf(i + 1) + ' ' + (j + 1) + '\n');
        br.close();
        bw.close();
    }
}