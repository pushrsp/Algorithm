import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static List<List<Integer>> G = new ArrayList<>();
    private static int[] P;

    private static int getParent(int node) {
        if (P[node] == node) {
            return node;
        }
        return P[node] = getParent(P[node]);
    }

    private static void union(int n1, int n2) {
        n1 = getParent(n1);
        n2 = getParent(n2);

        if (n1 < n2) {
            P[n1] = n2;
        } else {
            P[n2] = n1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
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

        // 완성된 그래프에서 노드를 삭제하는 방식은 시간 복잡도가 너무 커서
        // 오프라인 쿼리를 통해 빈 공간에 노드를 추가해 그래프를 만드는 방식을 채택
        final Stack<Integer> stack = new Stack<>();
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            stack.add(Integer.parseInt(st.nextToken()));
        }

        final Stack<Boolean> ret = new Stack<>();
        ret.add(false); // 마지막은 무조건 false

        final boolean[] visited = new boolean[N + 1];
        int group = 0;
        while (!stack.isEmpty()) {
            final int node = stack.pop();
            visited[node] = true;
            group++;

            // 추가하려는 노드가 연결된 노드 즉 자식 노드일 경우
            // 한 그룹에 속하므로 group--
            for (int child : G.get(node)) {
                if (!visited[child]) {
                    continue;
                }

                if (getParent(node) != getParent(child)) {
                    union(node, child);
                    group--;
                }
            }

            ret.add(group == 1);
        }

        while (!ret.isEmpty()) {
            final boolean ans = ret.pop();
            if (ans) {
                bw.write("CONNECT\n");
            } else {
                bw.write("DISCONNECT\n");
            }
        }

        br.close();
        bw.close();
    }
}