import java.io.*;
import java.util.*;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());

            final int power = Integer.parseInt(st.nextToken());
            l1.add(power);
            l2.add(power);
        }

        Collections.sort(l1);

        long ret = 0;
        for (int n = 0; n < N - 1; n++) {
            final int low = l1.get(n);

            Iterator<Integer> iterator = l2.iterator();
            while (iterator.hasNext()) {
                int curr = iterator.next();
                if (curr == low) {
                    int index = l2.indexOf(curr);
                    if (index == 0) {
                        int right = l2.get(index + 1);
                        ret += Math.abs(low - right);
                    } else if (index == l2.size() - 1) {
                        int left = l2.get(index - 1);
                        ret += Math.abs(low - left);
                    } else {
                        int right = l2.get(index + 1);
                        int left = l2.get(index - 1);
                        ret += Math.min(right - low, left - low);
                    }
                    iterator.remove();
                    break;
                }
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}