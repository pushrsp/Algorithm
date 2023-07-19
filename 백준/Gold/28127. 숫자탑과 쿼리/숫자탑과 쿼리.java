import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static long Q, A, D, X;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Q = Integer.parseInt(st.nextToken());
        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());

            A = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            X = Integer.parseInt(st.nextToken());

            long left = 1, right = (long) 1e6, ret = 0, pos = 0;
            while (left <= right) {
                long mid = (left + right) / 2;
                long cap = 1 + A * (mid - 1) + D * (mid - 1) * (mid - 2) / 2;

                if(cap <= X) {
                    left = mid + 1;
                    ret = mid;
                    pos = cap;
                } else {
                    right = mid - 1;
                }
            }

            bw.write(String.valueOf(ret) + ' ' + String.valueOf(X - pos + 1) + '\n');
        }

        bw.close();
        br.close();
    }
}
