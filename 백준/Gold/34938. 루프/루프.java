import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        char[] seq = br.readLine().toCharArray();

        // 방향: 0=북, 1=동, 2=남, 3=서
        int[] dirX = {0, 1, 0, -1};
        int[] dirY = {1, 0, -1, 0};

        // prefixDir[i] = seq[0..i-1] 실행 후의 방향 (시작 방향 0 기준)
        int[] prefixDir = new int[N + 1];
        prefixDir[0] = 0;
        for (int i = 0; i < N; i++) {
            if (seq[i] == 'L') {
                prefixDir[i + 1] = (prefixDir[i] + 3) % 4;
            } else if (seq[i] == 'R') {
                prefixDir[i + 1] = (prefixDir[i] + 1) % 4;
            } else {
                prefixDir[i + 1] = prefixDir[i];
            }
        }

        // 초기 상태 계산
        int turn = 0;
        int dx = 0, dy = 0;
        for (int i = 0; i < N; i++) {
            if (seq[i] == 'L') turn++;
            else if (seq[i] == 'R') turn--;
            else {
                dx += dirX[prefixDir[i]];
                dy += dirY[prefixDir[i]];
            }
        }
        turn = ((turn % 4) + 4) % 4;

        // 각 방향별 U 개수 (prefixDir[i]가 d일 때 seq[i]=='U'인 개수)
        int[] uCount = new int[4];
        for (int i = 0; i < N; i++) {
            if (seq[i] == 'U') {
                uCount[prefixDir[i]]++;
            }
        }

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken()) - 1;
            char newChar = st.nextToken().charAt(0);
            char oldChar = seq[idx];

            if (oldChar != newChar) {
                int dirAtIdx = prefixDir[idx];

                // 회전 변화량 계산
                int oldTurnDelta = (oldChar == 'L') ? 1 : (oldChar == 'R') ? -1 : 0;
                int newTurnDelta = (newChar == 'L') ? 1 : (newChar == 'R') ? -1 : 0;
                turn = ((turn - oldTurnDelta + newTurnDelta) % 4 + 4) % 4;

                // 방향 변화량 (idx 위치에서의 방향 변화)
                int oldDirDelta = (oldChar == 'L') ? 3 : (oldChar == 'R') ? 1 : 0;
                int newDirDelta = (newChar == 'L') ? 3 : (newChar == 'R') ? 1 : 0;
                int dirChange = (newDirDelta - oldDirDelta + 4) % 4; // idx 이후 방향이 이만큼 추가 회전

                // idx 위치의 U 처리
                if (oldChar == 'U') {
                    uCount[dirAtIdx]--;
                }
                if (newChar == 'U') {
                    uCount[dirAtIdx]++;
                }

                // idx 이후의 prefixDir 업데이트 및 U 재계산
                if (dirChange != 0) {
                    for (int i = idx + 1; i <= N; i++) {
                        int oldDir = prefixDir[i];
                        int newDir = (oldDir + dirChange) % 4;

                        if (i < N && seq[i] == 'U') {
                            uCount[oldDir]--;
                            uCount[newDir]++;
                        }

                        prefixDir[i] = newDir;
                    }
                }

                // dx, dy 재계산
                dx = uCount[1] - uCount[3]; // 동 - 서
                dy = uCount[0] - uCount[2]; // 북 - 남

                seq[idx] = newChar;
            }

            int answer;
            if (turn != 0) {
                answer = 0;
            } else if (dx == 0 && dy == 0) {
                answer = 0;
            } else {
                answer = 1;
            }

            sb.append(answer).append('\n');
        }

        System.out.print(sb);
    }
}
