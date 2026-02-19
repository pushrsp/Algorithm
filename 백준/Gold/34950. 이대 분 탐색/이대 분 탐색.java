import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static long L;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        L = Long.parseLong(st.nextToken());

        Set<Long> s = new HashSet<>();
        s.add(L);

        N -= 1;

        long left = 0, right = L;
        while (left < right) {
            long mid = (left + right) / 2;
            int count = 0;
            for (long i = left; i <= mid && count < (N + 1) / 2; i++) {
                s.add(i);
                count++;
            }

            N -= count;
            left = mid + 1;
        }

        for (long i = L; i >= 0 && N > 0; i--) {
            if (!s.contains(i)) {
                s.add(i);
                N--;
            }
        }

        for (Long ans : s) {
            bw.write(String.valueOf(ans) + ' ');
        }

        br.close();
        bw.close();
    }
}