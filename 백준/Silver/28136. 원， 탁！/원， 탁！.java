import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static final int[] ARR = new int[1000002];
    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int n = 1; n <= N; n++) {
            ARR[n] = Integer.parseInt(st.nextToken());
        }


        int ret = 0, i, prev = ARR[1];
        for (i = 2; i <= N; i++) {
            if(prev > ARR[i])
                break;

            prev = ARR[i];
        }

        Stack<Integer> stack = new Stack<>();
        for(int j = i; j <= N; j++) {
            if(!stack.isEmpty() && stack.peek() >= ARR[j]) {
                ret += 1;
                stack.clear();
            }

            stack.push(ARR[j]);
        }

        for (int j = 1; j <= i; j++) {
            if(!stack.isEmpty() && stack.peek() >= ARR[j]) {
                ret += 1;
                stack.clear();
            }

            stack.push(ARR[j]);
        }

        bw.write(String.valueOf(ret) + '\n');

        bw.close();
        br.close();
    }
}
