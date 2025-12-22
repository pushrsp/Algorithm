import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] a = new int[2 * N];
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int[] b = new int[2 * N];
        for (int i = 0; i < 2 * N; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }

        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < 2 * N; i++) {
            if (i < N) {
                if (a[i] != b[i]) {
                    bw.write("NO\n");
                    br.close();
                    bw.close();
                    return;
                }
                s.add(a[i]);
            } else {
                if (!s.contains(b[i])) {
                    bw.write("NO\n");
                    br.close();
                    bw.close();
                    return;
                }
                s.add(b[i]);
            }
        }

        bw.write("YES\n");

        br.close();
        bw.close();
    }
}