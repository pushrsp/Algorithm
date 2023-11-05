import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N, M, K;
    private static List<Score> Scores = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        Scores.sort((o1, o2) -> {
            if (o1.b == o2.b)
                return -Long.compare(o1.a, o2.a);

            return -Long.compare(o1.b, o2.b);
        });

        for (int i = 0; i < K; i++) {
            Scores.get(i).used = true;
        }

        Scores.sort((o1, o2) -> {
            if(o1.a == o2.a)
                return -Long.compare(o1.b, o2.b);

            return -Long.compare(o1.a, o2.a);
        });

        for (int i = 0; M > 0; i++) {
            if(!Scores.get(i).used) {
                Scores.get(i).used = true;
                M--;
            }
        }

        long ret = 0;
        for (Score score : Scores) {
            if(score.used)
                ret += score.a;
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            Score score = new Score();
            score.used = false;
            score.a = Integer.parseInt(st.nextToken());
            score.b = Integer.parseInt(st.nextToken());

            Scores.add(score);
        }
    }

    static class Score {
        public int a, b;
        public boolean used;
    }
}
