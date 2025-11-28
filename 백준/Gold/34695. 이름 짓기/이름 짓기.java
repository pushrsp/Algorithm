import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final long MOD = 1_000_000_007L;
    private static final int SIZE = 26;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        long[][] A = new long[SIZE][SIZE];

        for (int i = 0; i < K; i++) {
            String s = br.readLine();
            int from = s.charAt(0) - 'a';
            int to = s.charAt(1) - 'a';
            A[from][to] = 1;
        }

        // A + A^2 + A^3 + ... + A^(N-1) 의 모든 원소 합 구하기
        // 길이 2인 이름: A의 원소 합
        // 길이 3인 이름: A^2의 원소 합
        // ...
        // 길이 N인 이름: A^(N-1)의 원소 합

        long[][] sum = sumPowers(A, N - 1);

        long answer = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                answer = (answer + sum[i][j]) % MOD;
            }
        }

        System.out.println(answer);
        br.close();
    }

    // A + A^2 + ... + A^n 계산
    private static long[][] sumPowers(long[][] A, int n) {
        if (n == 0) {
            return new long[SIZE][SIZE]; // 영행렬
        }
        if (n == 1) {
            return copy(A);
        }

        if (n % 2 == 0) {
            // A + A^2 + ... + A^n = (I + A^(n/2)) * (A + A^2 + ... + A^(n/2))
            long[][] half = sumPowers(A, n / 2);
            long[][] Ahalf = power(A, n / 2);
            long[][] IplusAhalf = addIdentity(Ahalf);
            return multiply(IplusAhalf, half);
        } else {
            // A + A^2 + ... + A^n = (A + A^2 + ... + A^(n-1)) + A^n
            long[][] prev = sumPowers(A, n - 1);
            long[][] An = power(A, n);
            return add(prev, An);
        }
    }

    // A^n 계산
    private static long[][] power(long[][] A, int n) {
        if (n == 1) {
            return copy(A);
        }

        if (n % 2 == 0) {
            long[][] half = power(A, n / 2);
            return multiply(half, half);
        } else {
            return multiply(power(A, n - 1), A);
        }
    }

    private static long[][] multiply(long[][] A, long[][] B) {
        long[][] C = new long[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    private static long[][] add(long[][] A, long[][] B) {
        long[][] C = new long[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                C[i][j] = (A[i][j] + B[i][j]) % MOD;
            }
        }
        return C;
    }

    private static long[][] addIdentity(long[][] A) {
        long[][] C = copy(A);
        for (int i = 0; i < SIZE; i++) {
            C[i][i] = (C[i][i] + 1) % MOD;
        }
        return C;
    }

    private static long[][] copy(long[][] A) {
        long[][] C = new long[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            System.arraycopy(A[i], 0, C[i], 0, SIZE);
        }
        return C;
    }
}