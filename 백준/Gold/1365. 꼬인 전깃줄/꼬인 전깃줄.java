import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    private static int N;
    private static int[] Arr, DP;

    private static int Search(int left, int right, int target) {
        int mid;
        while (left < right) {
            mid = (left + right) / 2;

            if(DP[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return right;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        Arr = new int[N + 1];
        DP = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            Arr[i] = Integer.parseInt(st.nextToken());

        DP[0] = Arr[0];
        int i = 1, j = 0;
        while (i < N) {
            if(DP[j] < Arr[i]) {
                DP[j + 1] = Arr[i];
                j += 1;
            } else {
                DP[Search(0, j, Arr[i])] = Arr[i];
            }

            i++;
        }

        bw.write(String.valueOf(N - (j + 1)) + '\n');

        bw.close();
        br.close();
    }
}
