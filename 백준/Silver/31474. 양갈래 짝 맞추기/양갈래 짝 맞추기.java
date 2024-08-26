

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

        long ret = 1;
        for (long i = N; i > 0; i -= 2) {
            ret *= (i * (i - 1)) / 2;
            ret /= (i / 2);
        }

        bw.write(String.valueOf(ret));

        br.close();
        bw.close();
    }
}