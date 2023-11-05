import java.io.*;
import java.lang.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int L;
    private static int ML;
    private static int MK;
    private static int C;
    private static long[] Sum = new long[3000002];
    private static List<Integer> Zombies = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Zombies.add(-1);
        input(br, st);

        boolean success = true;
        for (int i = 1; i <= L; i++) {
            long curr = Sum[i - 1] - Sum[Math.max(0, i - ML)];
            if(Zombies.get(i) <= curr + MK) {
                Sum[i] = Sum[i - 1] + MK;
            } else {
                if(C > 0) {
                    C--;
                    Sum[i] = Sum[i - 1];
                } else {
                    bw.write("NO\n");
                    success = false;
                    break;
                }
            }
        }

        if(success) {
            bw.write("YES\n");
        }

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br, StringTokenizer st) throws IOException {
        L = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        ML = Integer.parseInt(st.nextToken());
        MK = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());

        for (int i = 0; i < L; i++) {
            st = new StringTokenizer(br.readLine());
            Zombies.add(Integer.parseInt(st.nextToken()));
        }
    }
}
