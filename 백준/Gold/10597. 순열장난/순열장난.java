import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static String S;
    private static int MAX;
    private static boolean find = false;
    private static boolean[] numbers = new boolean[51];
    private static List<Integer> temp = new ArrayList<>();
    private static List<Integer> answer = new ArrayList<>();

    private static int number(int i, int len) {
        return Integer.parseInt(S.substring(i, i + len));
    }

    private static void go(int i, long check) {
        if (find) {
            return;
        }

        if (i == S.length()) {
            find = true;
            answer.addAll(temp);
            return;
        }

        if (i + 1 <= S.length()) {
            int number = number(i, 1);
            if (number <= MAX && numbers[number] && ((1L << number) & check) == 0) {
                temp.add(number);
                go(i + 1, check | (1L << number));
                temp.remove(temp.size() - 1);
                if (find) {
                    return;
                }
            }
        }

        if (i + 2 <= S.length()) {
            int number = number(i, 2);
            if (number <= MAX && numbers[number] && ((1L << number) & check) == 0) {
                temp.add(number);
                go(i + 2, check | (1L << number));
                temp.remove(temp.size() - 1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        S = st.nextToken();

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 50; i++) {
            sb.append(i);
            MAX = i;
            numbers[i] = true;
            if (sb.length() == S.length()) {
                break;
            }
        }

        go(0, 0L);

        for (int i = 0; i < answer.size() - 1; i++) {
            bw.write(String.valueOf(answer.get(i)) + ' ');
        }

        bw.write(String.valueOf(answer.get(answer.size() - 1)) + '\n');

        br.close();
        bw.close();
    }
}