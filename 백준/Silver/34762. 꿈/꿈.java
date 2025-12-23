import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(br.readLine());

        boolean[] remember = new boolean[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int s = Integer.parseInt(st.nextToken());
            remember[s - 1] = true;
        }

        // nextRemember[i] = i 이상에서 가장 가까운 기억해야 할 날의 인덱스 (N이면 없음)
        int[] nextRemember = new int[N + 1];
        nextRemember[N] = N;
        for (int i = N - 1; i >= 0; i--) {
            nextRemember[i] = remember[i] ? i : nextRemember[i + 1];
        }

        int erased = -1;
        boolean success = true;

        for (int i = 0; i < N; i++) {
            boolean isErased = (i <= erased);
            boolean shouldRemember = remember[i];

            if (isErased && shouldRemember) {
                success = false;
                break;
            }

            if (!isErased && !shouldRemember) {
                int nextRem = nextRemember[i];
                
                int nightmareDay;
                if (nextRem > i + K) {
                    nightmareDay = Math.min(N - 1, i + K);
                } else {
                    nightmareDay = nextRem - 1;
                    if (nightmareDay < i) {
                        success = false;
                        break;
                    }
                }
                
                int eraseStart = Math.max(0, nightmareDay - K);
                int checkStart = Math.max(eraseStart, erased + 1);
                
                if (nextRemember[checkStart] <= nightmareDay) {
                    success = false;
                    break;
                }
                
                erased = nightmareDay;
            }
        }

        bw.write(success ? "YES\n" : "NO\n");
        br.close();
        bw.close();
    }
}