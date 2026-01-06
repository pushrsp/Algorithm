import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        String ret = "";
        int year = -1;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            String s = st.nextToken();
            int y = Integer.parseInt(st.nextToken());
            if (y == 2026) {
                ret = s;
            }
        }

        bw.write(ret + '\n');

        br.close();
        bw.close();
    }
}