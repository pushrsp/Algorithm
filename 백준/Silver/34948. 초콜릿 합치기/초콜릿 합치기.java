import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static List<Choco> chocos = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            chocos.add(new Choco());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            chocos.get(i).h = Long.parseLong(st.nextToken());
        }

        long ret = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            chocos.get(i).w = Long.parseLong(st.nextToken());
            ret = Math.max(ret, chocos.get(i).w * chocos.get(i).h);
        }

        chocos.sort(Comparator.comparingLong(c -> c.h));

        long prev = chocos.get(N - 1).h;
        long sum = chocos.get(N - 1).w;

        for (int i = N - 2; i >= 0; i--) {
            if (prev != chocos.get(i).h) {
                ret = Math.max(prev * sum, ret);
                prev = chocos.get(i).h;
            }

            sum += chocos.get(i).w;
        }

        ret = Math.max(prev * sum, ret);

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    static class Choco {
        long h, w;
    }

}