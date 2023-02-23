import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, K, A;
    private static Village[] villages;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        A = 1 << (N + 2);
        A -= 1;

        villages = new Village[N + 1];

        villages[0] = new Village(-1, -1);

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            villages[i] = new Village(-1, -1);
            villages[i].monster = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            villages[i].population = Integer.parseInt(st.nextToken());

        int ret = 0;

        for (int i = 3; i <= A; i++) {
            List<Village> temp = new ArrayList<>();
            for (int j = 1; j <= N; j++) {
                if ((i & (1 << j)) != 0)
                    temp.add(villages[j]);
            }

            if (temp.isEmpty())
                continue;

            Collections.sort(temp);

            int curHp = K - temp.get(0).monster;
            if (curHp < 0)
                continue;

            int population = temp.get(0).population;
            int damage = temp.get(0).monster;
            int idx = 1;

            while (curHp >= 0 && idx < temp.size()) {
                damage += temp.get(idx).monster;
                if (curHp - damage >= 0)
                    population += temp.get(idx).population;

                curHp -= damage;
                idx++;
            }

            ret = Math.max(ret, population);
        }

        bw.write(ret + "\n");

        bw.close();
        br.close();
    }

    static class Village implements Comparable<Village> {
        public int monster, population;

        public Village(int monster, int population) {
            this.monster = monster;
            this.population = population;
        }

        @Override
        public int compareTo(Village o) {
            if (monster < o.monster)
                return -1;
            else if (monster > o.monster)
                return 1;
            else
                return 0;
        }

    }
}
