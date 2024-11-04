import java.io.*;

public class Main {

    private static int[][] DP;
    private static int Y, X;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());

        String s1 = br.readLine();
        String s2 = br.readLine();

        Y = s2.length();
        X = s1.length();

        DP = new int[Y + 1][X + 1];

        for (int y = 1; y <= Y; y++) {
            for (int x = 1; x <= X; x++) {
                DP[y][x] = Math.max(Math.max(DP[y - 1][x - 1], DP[y - 1][x]), DP[y][x - 1]);
                if (s2.charAt(y - 1) == s1.charAt(x - 1)) {
                    DP[y][x] = Math.max(DP[y][x], DP[y - 1][x - 1] + 1);
                }
            }
        }

        bw.write(String.valueOf(DP[Y][X]) + '\n');

        br.close();
        bw.close();
    }
}