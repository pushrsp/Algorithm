import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T, K;

    private static long seconds(String s) {
        final String[] ss = s.split(":");

        long ret = Long.parseLong(ss[2]);
        ret += Long.parseLong(ss[1]) * 60;
        ret += Long.parseLong(ss[0]) * 3600;
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        final String s1 = st.nextToken();
        final String s2 = br.readLine();

        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        final long t = (long) (T * (100 - K)) / 100;

        final long t1 = seconds(s1);
        final long t2 = seconds(s2);

        if (t1 + t <= t2) {
            bw.write("1\n");
        } else {
            bw.write("0\n");
        }

        br.close();
        bw.close();
    }
}