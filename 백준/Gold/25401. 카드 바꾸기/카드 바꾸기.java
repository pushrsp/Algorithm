import java.io.*;
import java.util.*;

public class Main {

    private static int N;
    private static long[] A = new long[501];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }

        int ret = N - 1; // 최악의 경우: 하나만 유지

        // 두 위치를 고정하여 등차 결정 (등차 0인 경우 포함)
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long diff = A[j] - A[i];
                int dist = j - i;
                
                // 등차가 정수로 나누어떨어지는지 확인
                if (diff % dist != 0) continue;
                
                long d = diff / dist;
                
                // 이 등차로 몇 개를 바꿔야 하는지 계산
                int count = 0;
                for (int k = 0; k < N; k++) {
                    long expected = A[i] + (long)(k - i) * d;
                    if (A[k] != expected) {
                        count++;
                    }
                }
                
                ret = Math.min(ret, count);
            }
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}