import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    private static int Q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Q = Integer.parseInt(st.nextToken());

        TreeMap<Integer, Integer> m = new TreeMap<>();
        int cmd, num;
        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());

            cmd = Integer.parseInt(st.nextToken());
            if (cmd == 1) {
                num = Integer.parseInt(st.nextToken());
                m.put(num, m.getOrDefault(num, 0) + 1);
            } else if (cmd == 2) {
                num = Integer.parseInt(st.nextToken());
                if (m.containsKey(num)) {
                    m.replace(num, m.get(num) - 1);
                    if (m.get(num) == 0) {
                        m.remove(num);
                    }
                }
            } else {
                int ret = 0;
                if (!m.isEmpty()) {
                    Integer curr = m.firstKey();
                    ret++;
                    while ((curr = m.higherKey(curr * 2 - 1)) != null) {
                        ret++;
                    }
                }

                bw.write(String.valueOf(ret) + '\n');
            }
        }

        br.close();
        bw.close();
    }
}
