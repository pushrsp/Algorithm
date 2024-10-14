import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static int N, Q;
    private static int[] P, A;

    private static int getParent(int node) {
        if (P[node] == node) {
            return node;
        }
        return P[node] = getParent(P[node]);
    }

    private static void union(int n1, int n2) {
        n1 = getParent(n1);
        n2 = getParent(n2);

        if (n1 == n2) {
            return;
        }

        if (n1 < n2) {
            P[n2] = n1;
        } else {
            P[n1] = n2;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        P = new int[N + 1];
        A = new int[N + 1];

        for (int n = 0; n <= N; n++) {
            P[n] = n;
        }

        P[1] = 1;
        for (int i = 2; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
        }

        Stack<Command> commands = new Stack<>();
        int x, b, c, d;
        for (int i = 0; i < (N - 1) + Q; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());

            if (x == 0) {
                commands.push(new Command(0, Integer.parseInt(st.nextToken())));
            } else {
                commands.push(new Command(1, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
            }
        }

        Stack<Boolean> ret = new Stack<>();
        while (!commands.isEmpty()) {
            Command curr = commands.pop();
            if (curr.x == 0) {
                union(curr.b, A[curr.b]);
            } else {
                ret.add(getParent(curr.c) == getParent(curr.d));
            }
        }

        while (!ret.isEmpty()) {
            boolean ans = ret.pop();
            if (ans) {
                bw.write("YES\n");
            } else {
                bw.write("NO\n");
            }
        }

        br.close();
        bw.close();
    }

    static class Command {
        int x, b, c, d;

        Command(int x, int b) {
            this.x = x;
            this.b = b;
        }

        Command(int x, int c, int d) {
            this.x = x;
            this.c = c;
            this.d = d;
        }
    }
}