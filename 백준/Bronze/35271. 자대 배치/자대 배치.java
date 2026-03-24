import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static int[] A = new int[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            A[i + 1] = Integer.parseInt(st.nextToken());
        }

        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (A[a] > 0) {
                answer.add(a);
                A[a]--;
                continue;
            }

            if (A[b] > 0) {
                answer.add(b);
                A[b]--;
                continue;
            }

            if (A[c] > 0) {
                answer.add(c);
                A[c]--;
                continue;
            }

            answer.add(-1);
        }


        for (int i = 0; i < answer.size(); i++) {
            if (i == answer.size() - 1) {
                bw.write(String.valueOf(answer.get(i)));
            } else {
                bw.write(String.valueOf(answer.get(i)) + ' ');
            }
        }

        br.close();
        bw.close();
    }
}