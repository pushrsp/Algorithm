import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N, R1, C1, R2, C2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        R1 = Integer.parseInt(st.nextToken());
        C1 = Integer.parseInt(st.nextToken());
        R2 = Integer.parseInt(st.nextToken());
        C2 = Integer.parseInt(st.nextToken());

        int len = 2 * N - 1;
        int distance = N - 1;

        int centerY = N - 1, centerX = N - 1;
        for (int y = R1; y <= R2; y++) {
            int yy = y % len;
            int distanceY = Math.abs(yy - centerY);
            for (int x = C1; x <= C2; x++) {
                int xx = x % len;
                int distanceX = Math.abs(xx - centerX);

                if (distanceY + distanceX > distance) {
                    bw.write('.');
                } else {
                    bw.write(Character.toString(((distanceY + distanceX) % 26) + 'a'));
                }
            }
            bw.write('\n');
        }

        br.close();
        bw.close();
    }
}