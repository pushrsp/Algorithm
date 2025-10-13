import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int T, N;
    private static boolean[] P = new boolean[10_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        P[0] = P[1] = true;
        for (int i = 2; i * i <= 10_000; i++) {
            if (!P[i]) {
                for (int j = i * i; j <= 10_000; j += i) {
                    P[j] = true;
                }
            }
        }

        List<Integer> primeNumbers = new ArrayList<>();
        for (int i = 2; i <= 10_000; i++) {
            if (!P[i]) {
                primeNumbers.add(i);
            }
        }

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());

            List<int[]> answers = new ArrayList<>();
            for (Integer primeNumber : primeNumbers) {
                if (primeNumber - 1 == N) {
                    answers.add(new int[]{1, primeNumber});
                }
            }

            bw.write(String.valueOf(answers.size()) + '\n');
            for (int[] answer : answers) {
                bw.write(String.valueOf(answer[0]) + ' ' + answer[1] + '\n');
            }
        }

        br.close();
        bw.close();
    }
}