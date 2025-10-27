import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[][] adj = new int[1_001][1_001];
    private static Stack<Integer> answer = new Stack<>();

    private static void go(int curr) {
        for (int i = 1; i <= N; i++) {
            while (adj[curr][i] > 0) {
                adj[curr][i]--;
                adj[i][curr]--;
                go(i);
            }
        }
        answer.add(curr);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());

            int vertex = 0;
            for (int j = 1; j <= N; j++) {
                adj[i][j] = Integer.parseInt(st.nextToken());
                vertex += adj[i][j];
            }

            if (vertex % 2 != 0) {
                bw.write("-1\n");
                br.close();
                bw.close();
                return;
            }
        }

        go(1);

        while (!answer.isEmpty()) {
            bw.write(String.valueOf(answer.pop()) + ' ');
        }

        br.close();
        bw.close();
    }
}