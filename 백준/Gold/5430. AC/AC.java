import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T, N;
    private static String P, X;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            P = br.readLine();
            N = Integer.parseInt(br.readLine());
            X = br.readLine();

            String temp = X.substring(1, X.length() - 1);
            int[] arr = new int[N];
            
            // 빈 배열이 아닐 때만 파싱
            if (!temp.isEmpty()) {
                String[] numArr = temp.split(",");
                for (int i = 0; i < N; i++) {
                    arr[i] = Integer.parseInt(numArr[i]);
                }
            }

            int left = 0, right = N;  // right를 N으로 (N-1이 아님)
            boolean reversed = false;
            boolean error = false;
            
            for (int i = 0; i < P.length(); i++) {
                if (P.charAt(i) == 'R') {
                    reversed = !reversed;
                } else {  // D
                    // D 연산 전에 에러 체크
                    if (left == right) {
                        error = true;
                        break;
                    }
                    
                    if (reversed) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }

            if (error) {
                bw.write("error\n");
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append('[');
                
                // left != right 일 때만 출력 (빈 배열이 아닐 때)
                if (left != right) {
                    if (reversed) {
                        for (int i = right - 1; i > left; i--) {
                            sb.append(arr[i]).append(',');
                        }
                        sb.append(arr[left]);
                    } else {
                        for (int i = left; i < right - 1; i++) {
                            sb.append(arr[i]).append(',');
                        }
                        sb.append(arr[right - 1]);
                    }
                }
                sb.append(']');

                bw.write(sb.toString() + '\n');
            }
        }

        br.close();
        bw.close();
    }
}