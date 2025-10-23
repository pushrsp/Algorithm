import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[][] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        A = new int[N][M];
        long totalSum = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
                totalSum += A[i][j];
            }
        }

        long left = 0;
        long right = totalSum; // P의 최댓값은 모든 눈의 합
        long answer = right;

        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (canClear(mid)) {
                // mid 성능으로 제설 가능 -> 더 작은 P를 찾아본다.
                answer = mid;
                right = mid - 1;
            } else {
                // mid 성능으로 제설 불가능 -> 더 큰 P가 필요하다.
                left = mid + 1;
            }
        }

        System.out.println(answer);
    }

    /**
     * 주어진 성능 P로 모든 눈을 제거할 수 있는지 판별하는 함수
     *
     * @param p 현재 확인하려는 로봇의 성능
     * @return 제설 가능 여부 (true/false)
     */
    private static boolean canClear(long p) {
        long[] rowSums = new long[N];
        long[] colSums = new long[M];
        boolean[] rowCleared = new boolean[N];
        boolean[] colCleared = new boolean[M];

        // 각 행과 열의 초기 눈의 합 계산
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                rowSums[i] += A[i][j];
                colSums[j] += A[i][j];
            }
        }

        int totalClearedCount = 0;

        while (true) {
            List<Integer> rowsToClear = new ArrayList<>();
            List<Integer> colsToClear = new ArrayList<>();

            // P 이하의 성능으로 제거할 수 있는 행을 찾는다.
            for (int i = 0; i < N; i++) {
                if (!rowCleared[i] && rowSums[i] <= p) {
                    rowsToClear.add(i);
                }
            }

            // P 이하의 성능으로 제거할 수 있는 열을 찾는다.
            for (int j = 0; j < M; j++) {
                if (!colCleared[j] && colSums[j] <= p) {
                    colsToClear.add(j);
                }
            }

            // 더 이상 제거할 행이나 열이 없으면 루프 탈출
            if (rowsToClear.isEmpty() && colsToClear.isEmpty()) {
                break;
            }

            // 찾은 행들을 제거 처리
            for (int r : rowsToClear) {
                rowCleared[r] = true;
                totalClearedCount++;
                // 해당 행이 제거되었으므로, 각 열의 합에서 눈의 양을 빼준다.
                for (int j = 0; j < M; j++) {
                    if (!colCleared[j]) { // 아직 제거되지 않은 열에 대해서만
                        colSums[j] -= A[r][j];
                    }
                }
            }

            // 찾은 열들을 제거 처리
            for (int c : colsToClear) {
                colCleared[c] = true;
                totalClearedCount++;
                // 해당 열이 제거되었으므로, 각 행의 합에서 눈의 양을 빼준다.
                for (int i = 0; i < N; i++) {
                    if (!rowCleared[i]) { // 아직 제거되지 않은 행에 대해서만
                        rowSums[i] -= A[i][c];
                    }
                }
            }
        }

        // 모든 행과 열의 눈이 0이 되었는지 확인
        long remainingSnow = 0;
        for (int i = 0; i < N; i++) {
            if (!rowCleared[i]) {
                remainingSnow += rowSums[i];
            }
        }

        return remainingSnow == 0;
    }
}