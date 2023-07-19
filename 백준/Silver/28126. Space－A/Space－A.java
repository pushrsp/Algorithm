import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static int N, K, U, X, R;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        String cmd = st.nextToken();

        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < cmd.length(); i++) {
            if(cmd.charAt(i) == 'U')
                U++;
            else if(cmd.charAt(i) == 'X')
                X++;
            else
                R++;
        }

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        int ret = 0, x, y;
        for (int k = 0; k < K; k++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            int min = Math.min(y, x) - 1;
            if(min > 0) {
                y -= Math.min(X, min);
                x -= Math.min(X, min);
            }

            y -= Math.min(U, Math.abs(1 - y));
            x -= Math.min(R, Math.abs(1 - x));

            if(x == 1 && y == 1)
                ret += 1;
        }

        bw.write(String.valueOf(ret) + '\n');

        bw.close();
        br.close();
    }
}
