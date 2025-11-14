import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int T, L, N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            L = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());

            List<Integer> ants = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                ants.add(Integer.parseInt(st.nextToken()));
            }

            int min = 0, max = 0;
            for (Integer ant : ants) {
                min = Math.max(min, Math.min(ant, L - ant));
                max = Math.max(max, Math.max(ant, L - ant));
            }

            bw.write(String.valueOf(min) + ' ' + max + '\n');
        }

        br.close();
        bw.close();
    }
}