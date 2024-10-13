import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static List<List<Integer>> G = new ArrayList<>();
    private static boolean[] E;
    private static int[] P;

    private static int getParent(int node) {
        if (P[node] == node) {
            return node;
        }
        return P[node] = getParent(P[node]);
    }

    private static boolean isSame(int n1, int n2) {
        n1 = getParent(n1);
        n2 = getParent(n2);
        return n1 == n2;
    }

    private static void union(int n1, int n2) {
        n1 = getParent(n1);
        n2 = getParent(n2);
        P[n2] = n1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        E = new boolean[N + 1];
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

        List<Integer> erase = new ArrayList<>();
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            erase.add(Integer.parseInt(st.nextToken()));
        }

        List<Boolean> ans = new ArrayList<>();
        ans.add(false);

        int cnt = 0;
        for (int i = N - 1; i >= 0; i--) {
            int node = erase.get(i);
            E[node] = true;
            cnt++;
            for (int next : G.get(node)) {
                if (!E[next]) {
                    continue;
                }
                if (!isSame(node, next)) {
                    union(node, next);
                    cnt--;
                }
            }
            ans.add(cnt == 1);
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans.get(i)) {
                bw.write("CONNECT\n");
            } else {
                bw.write("DISCONNECT\n");
            }
        }

        br.close();
        bw.close();
    }
}