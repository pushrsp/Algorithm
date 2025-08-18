import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, T;
    private static Long[] A;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        A = new Long[N + 1];

        st = new StringTokenizer(br.readLine());
        List<Long> temp = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (i <= T) {
                temp.add(Long.parseLong(st.nextToken()));
            } else {
                A[i] = Long.parseLong(st.nextToken());
            }
        }

        Collections.sort(temp);

        for (int i = 0; i < T; i++) {
            A[i + 1] = temp.get(i);
        }

        for (int i = 1; i <= N; i++) {
            if (i == N) {
                bw.write(String.valueOf(A[i]) + '\n');
            } else {
                bw.write(String.valueOf(A[i]) + ' ');
            }
        }

        br.close();
        bw.close();
    }
}