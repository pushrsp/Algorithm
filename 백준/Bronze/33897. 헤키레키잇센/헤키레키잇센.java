import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        List<Integer> arr = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        int max = 1, count = 1, ret = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i) >= arr.get(i - 1)) {
                max++;
            } else {
                ret = Math.max(ret, max);
                count++;
                max = 1;
            }
        }
        ret = Math.max(ret, max);

        bw.write(String.valueOf(count) + ' ' + ret + '\n');
        br.close();
        bw.close();
    }
}