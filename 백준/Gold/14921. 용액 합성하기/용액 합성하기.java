import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] arr;

    private static int search(int target) {
        int left = 0, right = N - 1;
        if (target <= arr[left]) {
            return left;
        }
        if (target >= arr[right]) {
            return right;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 이 시점에서 left와 right는 target을 중심으로 위치함
        // 가장 가까운 값을 찾음
        if (Math.abs(arr[left] - target) < Math.abs(arr[right] - target)) {
            return left;
        } else {
            return right;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        arr = new int[N];

        st = new StringTokenizer(br.readLine());

        for (int n = 0; n < N; n++) {
            arr[n] = Integer.parseInt(st.nextToken());
        }

        int ret = arr[0] + arr[N - 1];
        for (int n = 0; n < N; n++) {
            int pos = search(-arr[n]);
            if (pos == n) {
                continue;
            }

            if (Math.abs(arr[n] + arr[pos]) < Math.abs(ret)) {
                ret = arr[n] + arr[pos];
            }
        }

        bw.write(String.valueOf(ret) + '\n');
        br.close();
        bw.close();
    }
}