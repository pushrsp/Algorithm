import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static void rotate(List<List<Integer>> map) {
        int n = map.size();
        int m = map.get(0).size();

        List<List<Integer>> ret = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                temp.add(map.get(n - 1 - j).get(i));
            }

            ret.add(temp);
        }

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                System.out.print(String.valueOf(ret.get(y).get(x)) + ' ');
            }

            System.out.println();
        }
    }

    static int N, M;
    static int[] A = new int[10001];
    static List<List<V>> G = new ArrayList<>();
    static int[] E = new int[10001];
    static int[] W = new int[10001];

    static class V {
        int e, w;

        V(int e, int w) {
            this.e = e;
            this.w = w;
        }
    }

    static class Pair {
        int v, day;

        Pair(int v, int day) {
            this.v = v;
            this.day = day;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int n = 0; n <= N; n++) {
            G.add(new ArrayList<>());
        }

        int s, e, w;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            E[e]++;
            G.get(s).add(new V(e, w));
        }

        Queue<Integer> q = new LinkedList<>();
        for (int n = 1; n <= N; n++) {
            if (E[n] == 0) {
                q.add(n);
                W[n] = 1;
            }
        }

        while (!q.isEmpty()) {
            Integer curr = q.poll();
            for (V v : G.get(curr)) {
                int next = v.e;
                int wait = v.w;
                E[next]--;

                if (wait >= 7) {
                    W[next] = Math.max(W[next], W[curr] + wait + 1);
                } else {
                    W[next] = Math.max(W[next], W[curr] + wait);
                }

                if (E[next] == 0) {
                    q.add(next);
                }
            }
        }

        int ret = 0;
        for (int n = 1; n <= N; n++) {
            ret = Math.max(ret, W[n]);
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}
