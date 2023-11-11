import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static String S, T;
    private static int ans = 0;

    private static void go(String t) {
        if(S.equals(t)) {
            ans = 1;
            return;
        }

        if(S.length() >= t.length()) {
            return;
        }

        if(t.charAt(t.length() - 1) == 'A') {
            StringBuilder sb = new StringBuilder(t);
            sb.deleteCharAt(sb.length() - 1);
            go(sb.toString());
        }

        if(t.charAt(0) == 'B') {
            StringBuilder sb = new StringBuilder(t);
            sb.deleteCharAt(0);
            sb.reverse();
            go(sb.toString());
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br, bw);

        if(S.length() == T.length()) {
            if(S.equals(T)) {
                bw.write(String.valueOf(1) + '\n');
                return;
            }
        }

        go(T);

        bw.write(String.valueOf(ans) + '\n');

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br, BufferedWriter bw) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        S = st.nextToken();

        st = new StringTokenizer(br.readLine());

        T = st.nextToken();
    }
}
