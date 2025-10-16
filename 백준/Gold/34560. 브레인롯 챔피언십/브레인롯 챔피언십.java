import java.io.*;
import java.util.*;

public class Main {

    private static int N;
    private static Map<String, Integer> champToIdx = new HashMap<>();
    private static List<List<Integer>> G = new ArrayList<>();
    private static boolean[][] v = new boolean[3_001][3_001];

    private static boolean hasCycle() {
        int[] color = new int[N];  // 0: 미방문, 1: 진행중, 2: 완료

        for (int i = 0; i < N; i++) {
            if (color[i] == 0) {
                if (dfs(i, color)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean dfs(int node, int[] color) {
        color[node] = 1;

        for (int next : G.get(node)) {
            if (color[next] == 1) {
                return true;
            }
            if (color[next] == 0 && dfs(next, color)) {
                return true;
            }
        }

        color[node] = 2;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N; i++) {
            G.add(new ArrayList<>());
        }

        List<Champion> champions = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            Champion champion = new Champion();
            champion.name = st.nextToken();
            champion.p = Integer.parseInt(st.nextToken());
            champion.a = Integer.parseInt(st.nextToken());
            champion.s = Integer.parseInt(st.nextToken());
            champions.add(champion);
            champToIdx.put(champion.name, i);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j == i || v[i][j] || v[j][i]) {
                    continue;
                }

                final Champion champ1 = champions.get(i);
                final Champion champ2 = champions.get(j);

                int s1 = 0, s2 = 0;
                if (champ1.p >= champ2.p) s1++;
                if (champ2.p >= champ1.p) s2++;

                if (champ1.a >= champ2.a) s1++;
                if (champ2.a >= champ1.a) s2++;

                if (champ1.s >= champ2.s) s1++;
                if (champ2.s >= champ1.s) s2++;

                if (s1 > s2) {
                    G.get(i).add(j);
                    champ1.w++;
                } else if (s1 < s2) {
                    G.get(j).add(i);
                    champ2.w++;
                }
                v[i][j] = true;
                v[j][i] = true;
            }
        }

        boolean paradox = hasCycle();

        if (paradox) {
            bw.write("Paradoxe Absurdo\n");
        } else {
            List<String> answer = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                boolean undefeated = true;

                for (int j = 0; j < N; j++) {
                    if (i != j && G.get(j).contains(i)) {
                        undefeated = false;
                        break;
                    }
                }

                if (undefeated) {
                    answer.add(champions.get(i).name);
                }
            }

            answer.sort(String::compareTo);

            for (String s : answer) {
                bw.write(s + '\n');
            }
        }

        bw.close();
        br.close();
    }

    static class Champion {
        String name;
        int p, a, s, w;
    }
}