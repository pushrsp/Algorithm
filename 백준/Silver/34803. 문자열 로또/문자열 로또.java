import java.io.*;
import java.util.*;

public class Main {

    private static int L, N, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        List<String> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(br.readLine());
        }

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        Map<String, Boolean> m = new HashMap<>();
        for (String s : list) {
            for (int i = 0; i <= L - K; i++) {
                m.put(s.substring(i, i + K), true);
            }
        }

        int ret = 0;
        for (String key : m.keySet()) {
            int sum = 0;
            for (String s : list) {
                for (int i = 0; i <= L - K; i++) {
                    if (key.equals(s.substring(i, i + K))) {
                        sum += 1;
                    }
                }
            }

            ret = Math.max(ret, sum);
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}