import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static boolean[] V;
    private static int[] P;
    private static List<List<Integer>> G = new ArrayList<>();

    private static int getParent(int n) {
        if (P[n] == n) {
            return n;
        }
        return P[n] = getParent(P[n]);
    }

    private static void union(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if (a < b) {
            P[b] = a;
        } else {
            P[a] = b;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        V = new boolean[N + 1];
        P = new int[N + 1];
        for (int n = 0; n <= N; n++) {
            G.add(new ArrayList<>());
            P[n] = n;
        }

        int a, b;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            G.get(a).add(b);
            G.get(b).add(a);
        }

        Stack<Integer> stack = new Stack<>();
        for (int n = 0; n < N; n++) {
            stack.push(Integer.parseInt(br.readLine()));
        }

        Stack<Boolean> ans = new Stack<>();
        ans.add(false);

        int component = 0;
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            V[curr] = true;
            component++;

            for (int child : G.get(curr)) {
                if (!V[child]) {
                    continue;
                }

                if (getParent(curr) != getParent(child)) {
                    union(curr, child);
                    component--;
                }
            }
            ans.add(component == 1);
        }

        while (!ans.isEmpty()) {
            boolean ret = ans.pop();
            if (ret) {
                bw.write("CONNECT\n");
            } else {
                bw.write("DISCONNECT\n");
            }
        }

        br.close();
        bw.close();
    }
}