import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {

    private static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        List<List<String>> board = new ArrayList<>();
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());

            board.add(new ArrayList<>());
            for (int x = 0; x < M; x++) {
                board.get(y).add(st.nextToken());
            }
        }

        List<String> answer = new ArrayList<>();
        for (int y = 0; y < N - 1; y++) {
            for (int x = 0; x < M; x++) {
                if(board.get(y).get(x).equals(board.get(y + 1).get(x)))
                    answer.add(board.get(y).get(x));
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M - 1; x++) {
                if(board.get(y).get(x).equals(board.get(y).get(x + 1)))
                    answer.add(board.get(y).get(x));
            }
        }

        for (int y = 0; y < N - 2; y++) {
            for (int x = 0; x < M; x++) {
                if(board.get(y).get(x).equals(board.get(y + 2).get(x)))
                    answer.add(board.get(y).get(x));
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M - 2; x++) {
                if(board.get(y).get(x).equals(board.get(y).get(x + 2)))
                    answer.add(board.get(y).get(x));
            }
        }

        if(answer.isEmpty()) {
            System.out.println("MANIPULATED");
        } else {
            Collections.sort(answer);
            Set<String> set = new HashSet<>();

            for(String ans : answer) {
                if(!set.contains(ans)) {
                    System.out.println(ans);
                    set.add(ans);
                }
            }
        }

        bw.close();
        br.close();
    }
}
