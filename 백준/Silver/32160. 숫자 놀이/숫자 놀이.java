import java.awt.*;
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

        if (N == 2) {
            bw.write("1\n");
            bw.write("2 1");
        } else {
            List<Point> ret = new ArrayList<>();
            ret.add(new Point(N - 1, (N - 1) / 2));

            int a = N - 1 - ((N - 1) / 2);
            for (int i = N - 2; i > (N - 1) / 2; i--) {
                int max = Math.max(a, i);
                int min = Math.min(a, i);
                a = max - min;
                ret.add(new Point(max, min));
            }

            for (int i = ((N - 1) / 2) - 1; i >= 1; i--) {
                int max = Math.max(a, i);
                int min = Math.min(a, i);
                a = max - min;
                ret.add(new Point(max, min));
            }

            a = ret.get(ret.size() - 1).x - ret.get(ret.size() - 1).y;
            bw.write(String.valueOf(N - a) + '\n');

            for (Point p : ret) {
                bw.write(String.valueOf(p.x) + ' ' + String.valueOf(p.y) + '\n');
            }
            bw.write(String.valueOf(N) + ' ' + String.valueOf(a) + '\n');
        }

        br.close();
        bw.close();
    }
}