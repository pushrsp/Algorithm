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

        st = new StringTokenizer(br.readLine());

        final List<Long> arr = new ArrayList<>(N);
        for (int n = 0; n < N; n++) {
            arr.add(Long.parseLong(st.nextToken()));
        }

        if (N == 1) {
            bw.write(String.valueOf("koosaga\n"));
            br.close();
            bw.close();
            return;
        }

        long ans = arr.get(0);
        for (int i = 1; i < N; i++) {
            ans ^= arr.get(i);
        }

        if (ans == 0) {
            bw.write("cubelover\n");
        } else {
            bw.write("koosaga\n");
        }

        br.close();
        bw.close();
    }
}