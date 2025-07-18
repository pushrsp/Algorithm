import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final int[] numbers = {1, 2, 3};
    private static int N;
    private static List<String> candidates = new ArrayList<>();
    private static boolean found = false;

    private static boolean isValid(String str, int number) {
        if (str.isEmpty()) {
            return true;
        }

        String temp = str + number;
        for (int start = 0; start < temp.length() - 1; start++) {
            for (int end = start + 1; end < temp.length(); end++) {
                String head = temp.substring(start, end);
                if (end + head.length() > temp.length()) {
                    break;
                }

                String tail = temp.substring(end, end + head.length());
                if (head.equals(tail)) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void go(String str) {
        if (str.length() == N) {
            candidates.add(str);
            found = true;
            return;
        }
        for (int number : numbers) {
            if (isValid(str, number)) {
                go(str + number);
            }
            if (found) {
                return;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        if (N == 1) {
            bw.write("1\n");
        } else {
            go("");
            Collections.sort(candidates);
            bw.write(candidates.get(0) + '\n');
        }

        br.close();
        bw.close();
    }
}