import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    private static int[] parent;
    private static int[] size;

    private static int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    private static void merge(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if (p1 == p2) return;
        if (size[p1] > size[p2]) {
            size[p1] += size[p2];
            parent[p2] = p1;
        } else {
            size[p2] += size[p1];
            parent[p1] = p2;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine().trim());

        parent = new int[N];
        size = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        // mapping1: 대표 인덱스 -> 현재 값
        // mapping2: 현재 값 -> 대표 인덱스
        HashMap<Integer, Integer> mapping1 = new HashMap<>();
        HashMap<Integer, Integer> mapping2 = new HashMap<>();

        int[] A = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            if (mapping2.containsKey(A[i])) {
                int j = mapping2.get(A[i]);
                mapping1.remove(j);
                merge(i, j);
                int rep = find(i);
                mapping2.put(A[i], rep);
                mapping1.put(rep, A[i]);
            } else {
                mapping2.put(A[i], i);
                mapping1.put(i, A[i]);
            }
        }

        int M = Integer.parseInt(br.readLine().trim());
        int query, x, y, z;
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            query = Integer.parseInt(st.nextToken());
            if (query == 1) {
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                if (x == y) continue;
                if (!mapping2.containsKey(x)) continue;
                if (mapping2.containsKey(y)) {
                    int node1 = mapping2.get(x);
                    int node2 = mapping2.get(y);
                    merge(node1, node2);
                    int rep = find(node1);
                    mapping2.remove(x);
                    mapping2.put(y, rep);
                    mapping1.remove(node1);
                    mapping1.remove(node2);
                    mapping1.put(rep, y);
                } else {
                    int node1 = mapping2.get(x);
                    mapping1.put(node1, y);
                    mapping2.remove(x);
                    mapping2.put(y, node1);
                }
            } else {
                z = Integer.parseInt(st.nextToken());
                z--;
                int rep = find(z);
                bw.write(String.valueOf(mapping1.get(rep)) + '\n');
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}