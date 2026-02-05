import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a, b, c, d;
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        int shuttle = a + b;
        int walk = c;

        if (Math.min(shuttle, walk) > d) {
            bw.write("T.T\n");
        } else if (Math.max(shuttle, walk) <= d) {
            bw.write("~.~\n");
        } else if (walk <= d) {
            bw.write("Walk\n");
        } else {
            bw.write("Shuttle\n");
        }

        br.close();
        bw.close();
    }
}