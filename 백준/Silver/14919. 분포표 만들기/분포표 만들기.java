import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static long M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());

        String[] s = br.readLine().split(" ");

        List<Long> nums = new ArrayList<>(s.length);
        for (String ss : s) {
            StringBuilder ssBuilder = new StringBuilder(ss);
            while (ssBuilder.length() < 8) {
                ssBuilder.append('0');
            }

            nums.add(Long.parseLong(ssBuilder.substring(2)));
        }

        Collections.sort(nums);

        long index = 1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.get(i) * M < 1000000 * index) {
                cnt++;
            } else {
                bw.write(String.valueOf(cnt) + ' ');
                index++;
                cnt = 0;
                i--;
            }
        }

        while (index <= M) {
            bw.write(String.valueOf(cnt) + ' ');
            cnt = 0;
            index++;
        }

        bw.write('\n');

        br.close();
        bw.close();
    }
}