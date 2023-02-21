import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {


    private static int N, ret = 987654321;
    private static boolean[] visited;
    private static int[] potions;
    private static ArrayList<Pair>[] discounts;

    private static void go(int count, int sum) {
        if (count == N) {
            ret = Math.min(ret, sum);
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (visited[i])
                continue;

            visited[i] = true;
            for (Pair pair : discounts[i])
                potions[pair.index] -= pair.price;

            go(count + 1, sum + Math.max(1, potions[i]));

            for (Pair pair : discounts[i])
                potions[pair.index] += pair.price;

            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        potions = new int[N + 1];
        visited = new boolean[N + 1];
        discounts = new ArrayList[N + 1];

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            potions[i] = Integer.parseInt(st.nextToken());
            discounts[i] = new ArrayList<Pair>();
        }

        int p, a, d;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());

            p = Integer.parseInt(st.nextToken());
            for (int j = 0; j < p; j++) {
                st = new StringTokenizer(br.readLine());

                a = Integer.parseInt(st.nextToken());
                d = Integer.parseInt(st.nextToken());

                discounts[i].add(new Pair(a, d));
            }
        }

        go(0, 0);

        bw.write(String.valueOf(ret));

        bw.close();
        br.close();
    }

    static class Pair {
        int index, price;

        public Pair(int index, int price) {
            this.index = index;
            this.price = price;
        }
    }
}
