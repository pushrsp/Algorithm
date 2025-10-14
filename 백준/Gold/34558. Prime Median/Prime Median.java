import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static boolean[] isNotPrime = new boolean[1_000_001];
    private static List<Integer> primes = new ArrayList<>();

    // a 이상의 첫 번째 소수 인덱스 찾기 (lower_bound)
    private static int lowerBound(int target) {
        int left = 0, right = primes.size() - 1;
        int result = primes.size();
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (primes.get(mid) >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    // b 이하의 마지막 소수 인덱스 찾기
    private static int upperBound(int target) {
        int left = 0, right = primes.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (primes.get(mid) <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 에라토스테네스의 체
        isNotPrime[0] = isNotPrime[1] = true;
        for (int i = 2; i * i <= 1_000_000; i++) {
            if (!isNotPrime[i]) {
                for (int j = i * i; j <= 1_000_000; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }

        // 소수 리스트 생성
        for (int i = 2; i <= 1_000_000; i++) {
            if (!isNotPrime[i]) {
                primes.add(i);
            }
        }

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int leftIdx = lowerBound(a);
            int rightIdx = upperBound(b);

            // 범위 내에 소수가 있는지 확인
            if (leftIdx <= rightIdx && rightIdx >= 0 && leftIdx < primes.size()) {
                int count = rightIdx - leftIdx + 1;
                
                if (count % 2 == 1) {
                    // 홀수 개면 중앙값 출력
                    int medianIdx = (leftIdx + rightIdx) / 2;
                    bw.write(primes.get(medianIdx) + "\n");
                } else {
                    // 짝수 개면 -1 출력
                    bw.write("-1\n");
                }
            } else {
                // 소수가 없으면 -1 출력
                bw.write("-1\n");
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }
}