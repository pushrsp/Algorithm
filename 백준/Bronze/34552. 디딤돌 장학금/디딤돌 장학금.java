import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] M = new int[12];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 11; i++) {
            M[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        int ret = 0;

        int b, s, l;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            b = Integer.parseInt(st.nextToken());
            l = (int) Double.parseDouble(st.nextToken()) * 100;
            s = Integer.parseInt(st.nextToken());

            if (l >= 200 && s >= 17) {
                ret += M[b];
            }
        }

        bw.write(String.valueOf(ret) + '\n');
        br.close();
        bw.close();
    }
}