import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        final List<long[]> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            long[] a = new long[2];
            a[0] = Long.parseLong(st.nextToken());
            a[1] = Long.parseLong(st.nextToken());

            list.add(a);
        }

        long ret = 0;
        long n1 = list.get(0)[0], n2 = list.get(0)[1];
        for (int i = 1; i < N; i++) {
            long n3 = list.get(i)[0], n4 = list.get(i)[1];
            if (n3 <= n2) {
                n2 = Math.max(n2, n4);
            } else {
                ret += Math.abs(n2 - n1);
                n1 = n3;
                n2 = n4;
            }
        }

        ret += Math.abs(n2 - n1);

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}