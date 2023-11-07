import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N, M;
    private static int[] parent = new int[200001];
    private static long[] population = new long[200001];
    private static long[] sum = new long[200001];
    private static long prev = 0;
    private static List<Pair> pairs = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        for (Pair pair : pairs) {
            int a = pair.a;
            int b = pair.b;

            union(a, b);

            bw.write(String.valueOf(N + prev) + '\n');
        }

        br.close();
        bw.close();
    }

    private static int getParent(int n) {
        if(n == parent[n]) {
            return n;
        }

        return parent[n] = getParent(parent[n]);
    }

    private static void union(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if(a == b) {
            return;
        }

        long ret = 0;
        if(a < b) {
            parent[b] = a;
            for (long i = population[a]; i < population[a] + population[b]; i++) {
                ret += i;
            }

            population[a] += population[b];
            population[b] = 0;

            prev -= sum[b];
            sum[b] = 0;

            prev += ret;
            sum[a] += ret;
        } else {
            parent[a] = b;
            for (long i = population[b]; i < population[a] + population[b]; i++) {
                ret += i;
            }

            population[b] += population[a];
            population[a] = 0;

            prev -= sum[a];
            sum[a] = 0;

            prev += ret;
            sum[b] += ret;
        }
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int n = 0; n <= N; n++) {
            parent[n] = n;
            population[n] = 1;
            sum[n] = 0;
        }

        int a, b;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            pairs.add(new Pair(a, b));
        }
    }

    static class Pair {
        public int a, b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
