import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static int T;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        int s, n;
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            List<Integer> pos = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                pos.add(Integer.parseInt(st.nextToken()));
            }

            int shortest = 0, longest = 0;
            for (Integer p : pos) {
                if (Math.min(p, s - p) - shortest > 0) {
                    shortest += Math.min(p, s - p) - shortest;
                }
                if (Math.max(p, s - p) - longest > 0) {
                    longest += Math.max(p, s - p) - longest;
                }
            }

            Collections.sort(pos);

            bw.write(String.valueOf(shortest) + ' ' + String.valueOf(longest) + '\n');
        }

        br.close();
        bw.close();
    }
}