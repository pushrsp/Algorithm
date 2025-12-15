import java.io.*;
import java.util.*;

public class Main {

    private static int N, M;
    private static long[] score = new long[31];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Set<Long> visited = new HashSet<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            long bit = 0;
            for (int j = 0; j < x; j++) {
                int chapter = Integer.parseInt(st.nextToken());
                bit |= (1L << chapter);
            }
            visited.add(bit);
        }

        if (visited.size() == N) {
            for (Long l : visited) {
                List<Integer> chapters = new ArrayList<>();
                for (int i = 1; i <= M; i++) {
                    if ((l & (1 << i)) != 0) {
                        chapters.add(i);
                    }
                }
            }

            for (int i = 1; i < M; i++) {
                bw.write(String.valueOf((long) Math.pow(2, i - 1)) + ' ');
            }
            bw.write(String.valueOf((long) Math.pow(2, M - 1)) + '\n');
        } else {
            bw.write(String.valueOf(-1) + '\n');
        }

        br.close();
        bw.close();
    }
}