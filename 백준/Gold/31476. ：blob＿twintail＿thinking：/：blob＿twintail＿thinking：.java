import java.io.*;
import java.util.*;

public class Main {

    private static int D, N, U, T;
    private static int[] parent;
    private static List<Integer>[] G;
    private static int t, p, pl;

    private static void tree(int last) {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);

        int n = 2;
        parent[1] = 1;
        while (n < last) {
            int p = q.poll();

            G[p].add(n);
            G[p].add(n + 1);

            parent[n] = p;
            parent[n + 1] = p;

            q.add(n);
            q.add(n + 1);

            n += 2;
        }
    }

    private static void disconnect(int s, int e) {
        int n = e;
        while (true) {
            if (n % 2 == 0) {
                G[parent[n]].set(0, -1);
            } else {
                G[parent[n]].set(1, -1);
            }

            n = parent[n];
            if (n == s) {
                break;
            }
        }
    }

    private static void pony(int n) {
        pl = n;
        if (!G[n].isEmpty()) {
            if (G[n].get(0) != -1) {
                p += U;
                pony(G[n].get(0));
            }

            if (G[n].get(1) != -1) {
                p += U;
                pony(G[n].get(1));
            }
        }
        p += U;
    }

    private static void twin(int start) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(start, 0));

        int before = 0, cnt = 0;
        boolean check = false;
        while (!q.isEmpty()) {
            Pair curr = q.poll();

            if (before != curr.level) {
                if (check) {
                    cnt++;
                }

                t += (U + T * cnt);
                before = curr.level;
                check = false;
            }

            int c = 0;
            for (Integer a : G[curr.node]) {
                if (a != -1) {
                    c++;
                    q.add(new Pair(a, curr.level + 1));
                }
            }

            if (c == 2) {
                check = true;
            }
        }
    }

    private static int calc(int n) {
        int ret = 0;
        while (true) {
            if (n == 1) {
                break;
            }

            ret += U;
            n = parent[n];
        }

        return ret + U;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        D = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        U = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        int last = (int) Math.pow(2, D);
        parent = new int[last];

        G = new List[last];
        for (int i = 0; i < last; i++) {
            G[i] = new ArrayList<Integer>();
        }

        tree(last);

        int s, e;
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            disconnect(s, e);
        }

        pony(1);
        p -= calc(pl);
        twin(1);

        if (p > t) {
            bw.write(":blob_twintail_aww:\n");
        } else if (p < t) {
            bw.write(":blob_twintail_sad:\n");
        } else {
            bw.write(":blob_twintail_thinking:\n");
        }

        br.close();
        bw.close();
    }

    static class Pair {
        public int node, level;

        Pair(int node, int level) {
            this.node = node;
            this.level = level;
        }
    }
}
