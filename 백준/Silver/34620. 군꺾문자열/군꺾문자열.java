import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        Stack<Character> stack = new Stack<>();
        while (a != 0 && b != 0) {
            if (a - b >= 0) {
                a -= b;
                stack.push('G');
            } else {
                if (b % 2 == 0) {
                    stack.push('K');
                    b /= 2;
                } else {
                    bw.write(String.valueOf(-1) + '\n');
                    br.close();
                    bw.close();
                    return;
                }
            }
        }

        while (!stack.isEmpty()) {
            bw.write(String.valueOf(stack.pop()));
        }

        br.close();
        bw.close();
    }
}