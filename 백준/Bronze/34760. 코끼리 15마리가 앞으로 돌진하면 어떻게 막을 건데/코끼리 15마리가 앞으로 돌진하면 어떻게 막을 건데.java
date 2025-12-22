import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int[] A = new int[16];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int max = 0;
        for (int i = 1; i <= 14; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, A[i]);
        }

        A[15] = Integer.parseInt(st.nextToken());
        if (max + 1 >= A[15]) {
            bw.write(String.valueOf(max + 1) + '\n');
        } else {
            bw.write(String.valueOf(A[15]) + '\n');
        }

        br.close();
        bw.close();
    }
}