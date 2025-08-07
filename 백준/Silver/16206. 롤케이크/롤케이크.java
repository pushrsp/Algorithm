import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        List<Integer> ten = new ArrayList<>();
        List<Integer> numbers = new ArrayList<>();

        int ret = 0;
        for (int i = 0; i < N; i++) {
            final int number = Integer.parseInt(st.nextToken());
            if (number < 10) {
                continue;
            } else if (number == 10) {
                ret++;
            } else if (number % 10 == 0) {
                ten.add(number);
            } else {
                numbers.add(number);
            }
        }

        Collections.sort(ten);
        for (Integer number : ten) {
            if (M == 0) {
                break;
            }

            final int m = number / 10;
            final int cut = m - 1;
            if (M - cut < 0) {
                ret += M;
                M = 0;
            } else if (M - cut == 0) {
                ret += M + 1;
                M = 0;
            } else {
                M -= cut;
                ret += m;
            }
        }

        if (M > 0) {
            Collections.sort(numbers);
            for (Integer number : numbers) {
                if (M == 0) {
                    break;
                }

                final int m = number / 10;
                final int cut = m;
                if (M - cut <= 0) {
                    ret += M;
                    M = 0;
                } else {
                    M -= cut;
                    ret += m;
                }
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}