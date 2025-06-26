import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] A;
    private static int SUM;

    private static boolean go() {
        if (SUM % 3 != 0) {
            return false;
        }

        int count1 = SUM / 3;
        int count2 = 0;
        for (int height : A) {
            count2 += height / 2;
        }
        return count2 - count1 >= 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            SUM += A[i];
        }

        bw.write(go() ? "YES\n" : "NO\n");

        br.close();
        bw.close();
    }
}