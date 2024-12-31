import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] A = new int[1000001];
    private static int[] I = new int[1000001];

    private static int lowerBound(List<Integer> sorted, int target) {
        if (sorted.isEmpty()) {
            return 0;
        }

        int left = 0, right = sorted.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (sorted.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int n = 0; n < N; n++) {
            A[n] = Integer.parseInt(st.nextToken());
        }

        List<Integer> ans = new ArrayList<>();
        for (int n = 0; n < N; n++) {
            if (ans.isEmpty()) {
                I[n] = 0;
                ans.add(A[n]);
            } else {
                int index = lowerBound(ans, A[n]);
                I[n] = index;
                if (index == ans.size()) {
                    ans.add(A[n]);
                } else {
                    ans.set(index, A[n]);
                }
            }
        }

        bw.write(String.valueOf(ans.size()) + '\n');

        List<Integer> ret = new ArrayList<>();
        int index = ans.size() - 1;
        for (int n = N - 1; n >= 0; n--) {
            if (I[n] == index) {
                index--;
                ret.add(A[n]);
            }
        }

        for (int i = ret.size() - 1; i >= 1; i--) {
            bw.write(String.valueOf(ret.get(i)) + ' ');
        }

        if (!ret.isEmpty()) {
            bw.write(String.valueOf(ret.get(0)) + '\n');
        }

        br.close();
        bw.close();
    }
}