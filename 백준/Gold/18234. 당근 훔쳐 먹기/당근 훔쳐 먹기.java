import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, T;
    private static List<Carrot> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        arr = new ArrayList<>();

        long w, p;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            w = Long.parseLong(st.nextToken());
            p = Long.parseLong(st.nextToken());

            arr.add(new Carrot(w, p));
        }

        Collections.sort(arr);

        long ret = 0;
        int i = 0;
        for (int j = T - N; j < T; j++) {
            ret += arr.get(i).w + (arr.get(i).p * j);
            i += 1;
        }

        bw.write(String.valueOf(ret));

        bw.close();
        br.close();
    }

    static class Carrot implements Comparable<Carrot> {
        long w, p;

        public Carrot(long w, long p) {
            this.w = w;
            this.p = p;
        }

        @Override
        public int compareTo(Carrot o) {
            if (p < o.p)
                return -1;
            if (p > o.p)
                return 1;
            if (w < o.w)
                return -1;
            else if (w > o.w)
                return 1;
            else
                return 0;
        }

    }
}
