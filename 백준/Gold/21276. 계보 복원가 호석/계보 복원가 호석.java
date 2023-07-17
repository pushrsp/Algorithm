import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static final Map<String, Integer> nameToIdx = new HashMap<>();
    private static final Map<Integer, String> idxToName = new HashMap<>();
    private static final List<String> names = new ArrayList<>();
    private static final List<List<Integer>> adj = new ArrayList<>();
    private static final List<List<Integer>> answer = new ArrayList<>();

    private static int[] inDegree;

    private static int N, M;

    private static void sort(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int curr = q.poll();

            for(Integer next : adj.get(curr)) {
                if(--inDegree[next] == 0) {
                    q.add(next);
                    answer.get(curr).add(next);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        inDegree = new int[N];

        for (int n = 0; n < N; n++) {
            adj.add(new ArrayList<>());
            answer.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for (int n = 0; n < N; n++) {
            String name = st.nextToken();

            nameToIdx.put(name, n);
            idxToName.put(n, name);
            names.add(name);
        }

        Collections.sort(names);

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        String x, y;
        for (int m = 0; m < M; m++) {
            st = new StringTokenizer(br.readLine());
            x = st.nextToken();
            y = st.nextToken();

            adj.get(nameToIdx.get(y)).add(nameToIdx.get(x));
            inDegree[nameToIdx.get(x)]++;
        }

        List<String> parent = new ArrayList<>();
        for (int n = 0; n < N; n++) {
            if(inDegree[n] == 0)
                parent.add(idxToName.get(n));
        }

        Collections.sort(parent);

        bw.write(String.valueOf(parent.size()) + '\n');

        for(String name : parent) {
            bw.write(name + ' ');
            sort(nameToIdx.get(name));
        }

        bw.write('\n');

        for(String name : names) {
            bw.write(name + ' ');
            List<String> temp = new ArrayList<>();
            for(Integer idx : answer.get(nameToIdx.get(name))) {
                temp.add(idxToName.get(idx));
            }

            if(temp.isEmpty()) {
                bw.write(String.valueOf(0));
            } else {
                Collections.sort(temp);
                bw.write(String.valueOf(temp.size()) + ' ');

                for(String s : temp)
                    bw.write(s + ' ');
            }

            bw.write('\n');
        }

        bw.close();
        br.close();
    }
}
