import java.io.*;
import java.util.*;

public class Main {

    private static int N, Ans;
    private static String[] S = new String[11];
    private static List<Character> characters = new ArrayList<>();
    private static boolean[] visited = new boolean[31];
    private static int[] score = new int[31];

    private static void go(int count, int number) {
        if (count == characters.size()) {
            int ret = 0;
            for (int i = 0; i < N; i++) {
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < S[i].length(); j++) {
                    sb.append(score[S[i].charAt(j) - 'A']);
                }

                ret += Integer.parseInt(sb.toString());
            }

            Ans = Math.max(Ans, ret);
            return;
        }

        for (int i = 0; i < characters.size(); i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            int temp = score[characters.get(i) - 'A'];
            score[characters.get(i) - 'A'] = number;
            go(count + 1, number - 1);
            score[characters.get(i) - 'A'] = temp;
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        Set<Character> s = new HashSet<>();
        for (int i = 0; i < N; i++) {
            S[i] = br.readLine();

            for (int j = 0; j < S[i].length(); j++) {
                s.add(S[i].charAt(j));
            }
        }

        characters.addAll(s);

        go(0, 9);

        bw.write(String.valueOf(Ans) + '\n');

        br.close();
        bw.close();
    }
}