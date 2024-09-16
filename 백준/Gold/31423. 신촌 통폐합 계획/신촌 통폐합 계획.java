import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static String[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        arr = new String[N + 1];

        int[] next = new int[N + 1];
        int[] tail = new int[N + 1];
        for (int n = 1; n <= N; n++) {
            arr[n] = br.readLine();
            next[n] = n;
            tail[n] = n;
        }

        int p = -1;
        for (int n = 0; n < N - 1; n++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            next[tail[l]] = r;
            tail[l] = tail[r];
            p = l;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(arr[p]);
            p = next[p];
        }

        bw.write(sb.toString() + '\n');

        br.close();
        bw.close();
    }
}