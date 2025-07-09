import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    private static int N, D;
    private static List<int[]>[] ARR = new List[10_001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        int min = Integer.MAX_VALUE;
        int start, end, distance;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            distance = Integer.parseInt(st.nextToken());
            min = Math.min(min, start);
            if (ARR[start] == null) {
                ARR[start] = new ArrayList<>();
            }

            int[] pair = {end, distance};
            ARR[start].add(pair);
        }

        Queue<int[]> q = new LinkedList<>();
        int[] elem = {min, min};
        q.add(elem);

        int ret = D;
        while (!q.isEmpty()) {
            int pos = q.peek()[0];
            int dist = q.peek()[1];
            q.poll();

            if (pos > D) {
                continue;
            } else if (pos == D) {
                ret = Math.min(ret, dist);
                continue;
            }

            int[] i = {pos + 1, dist + 1};
            q.add(i);
            if (ARR[pos] != null) {
                for (int[] a : ARR[pos]) {
                    int[] z = {a[0], dist + a[1]};
                    q.add(z);
                }
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}