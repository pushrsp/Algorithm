import java.io.*;
import java.util.*;

public class Main {

    private static int N, MP, MF, MS, MV;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        MP = Integer.parseInt(st.nextToken());
        MF = Integer.parseInt(st.nextToken());
        MS = Integer.parseInt(st.nextToken());
        MV = Integer.parseInt(st.nextToken());

        List<int[]> foods = new ArrayList<>();
        int mp, mf, ms, mv, mc;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            mp = Integer.parseInt(st.nextToken());
            mf = Integer.parseInt(st.nextToken());
            ms = Integer.parseInt(st.nextToken());
            mv = Integer.parseInt(st.nextToken());
            mc = Integer.parseInt(st.nextToken());

            foods.add(new int[]{mp, mf, ms, mv, mc});
        }

        int ret = Integer.MAX_VALUE;
        int num = -1;
        TreeMap<Integer, List<String>> m = new TreeMap<>();
        for (int i = 1; i < (1 << N); i++) {
            int p = 0, f = 0, s = 0, v = 0, c = 0;
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) != 0) {
                    p += foods.get(j)[0];
                    f += foods.get(j)[1];
                    s += foods.get(j)[2];
                    v += foods.get(j)[3];
                    c += foods.get(j)[4];
                    if (sb.length() == 0) {
                        sb.append(j + 1);
                    } else {
                        sb.append(' ').append(j + 1);
                    }
                }
            }

            if (p >= MP && f >= MF && s >= MS && v >= MV && c <= ret) {
                if (!m.containsKey(c)) {
                    m.put(c, new ArrayList<>());
                }
                m.get(c).add(sb.toString());
                ret = c;
            }
        }

        if (ret == Integer.MAX_VALUE) {
            bw.write("-1\n");
        } else {
            int lowest = m.firstKey();
            bw.write(String.valueOf(lowest) + '\n');
            Collections.sort(m.get(lowest));
            bw.write(m.get(lowest).get(0) + '\n');
        }

        br.close();
        bw.close();
    }
}