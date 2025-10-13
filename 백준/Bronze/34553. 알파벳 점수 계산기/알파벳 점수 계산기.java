import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String s = st.nextToken();

        List<Integer> scores = new ArrayList<>();
        scores.add(1);

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) > s.charAt(i - 1)) {
                scores.add(scores.get(scores.size() - 1) + 1);
            } else {
                scores.add(1);
            }
        }

        int ret = 0;
        for (Integer score : scores) {
            ret += score;
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}