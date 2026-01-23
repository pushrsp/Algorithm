import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int K, N, F;
    private static boolean[][] adj = new boolean[901][901];
    private static List<Integer> result = new ArrayList<>();

    private static boolean go(List<Integer> selected, List<Integer> candidates) {
        if (selected.size() == K) {
            result.addAll(selected);
            return true;
        }

        if (selected.size() + candidates.size() < K) {
            return false;
        }

        for (int i = 0; i < candidates.size(); i++) {
            int next = candidates.get(i);

            List<Integer> newCandidates = new ArrayList<>();
            for (int j = i + 1; j < candidates.size(); j++) {
                int cand = candidates.get(j);
                if (adj[next][cand]) {
                    newCandidates.add(cand);
                }
            }

            selected.add(next);
            if (go(selected, newCandidates)) {
                return true;
            }
            selected.remove(selected.size() - 1);
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        F = Integer.parseInt(st.nextToken());

        int a, b;
        for (int i = 0; i < F; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            adj[a][b] = true;
            adj[b][a] = true;
        }

        List<Integer> candidates = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            candidates.add(i);
        }

        boolean found = go(new ArrayList<>(), candidates);

        if (found) {
            for (int node : result) {
                bw.write(node + "\n");
            }
        } else {
            bw.write("-1\n");
        }

        br.close();
        bw.close();
    }
}