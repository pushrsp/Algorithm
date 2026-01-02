import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int D = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            String N = br.readLine();

            // 가장 뒤에 있는 >= 2인 숫자의 위치 찾기
            int latestIndex = -1;
            for (int i = 0; i < D; i++) {
                if ((N.charAt(i) - '0') >= 2) {
                    latestIndex = i;
                }
            }

            StringBuilder left, right;
            if (latestIndex == -1) {
                // 모두 0 또는 1인 경우
                left = new StringBuilder();
                right = new StringBuilder(N);
            } else {
                left = new StringBuilder(N.substring(0, latestIndex + 1));
                right = new StringBuilder(N.substring(latestIndex + 1));
            }

            while (K-- > 0) {
                // 가장 뒤쪽의 >= 2인 숫자를 찾아서 9배
                int idx = -1;

                // right에서 뒤에서부터 찾기
                for (int i = right.length() - 1; i >= 0; i--) {
                    if ((right.charAt(i) - '0') >= 2) {
                        idx = i;
                        break;
                    }
                }

                if (idx != -1) {
                    // right에서 찾음
                    int val = (right.charAt(idx) - '0') * 9;
                    if (val >= 10) {
                        right.setCharAt(idx, (char) ('0' + val / 10));
                        right.insert(idx + 1, (char) ('0' + val % 10));
                    } else {
                        right.setCharAt(idx, (char) ('0' + val));
                    }
                } else {
                    // left에서 뒤에서부터 찾기
                    for (int i = left.length() - 1; i >= 0; i--) {
                        if ((left.charAt(i) - '0') >= 2) {
                            idx = i;
                            break;
                        }
                    }

                    if (idx != -1) {
                        // left에서 찾음
                        int val = (left.charAt(idx) - '0') * 9;
                        if (val >= 10) {
                            left.setCharAt(idx, (char) ('0' + val / 10));
                            left.insert(idx + 1, (char) ('0' + val % 10));
                        } else {
                            left.setCharAt(idx, (char) ('0' + val));
                        }
                    } else {
                        // 모두 0 또는 1, 맨 앞의 1을 9배
                        for (int i = 0; i < left.length(); i++) {
                            if (left.charAt(i) == '1') {
                                left.setCharAt(i, '9');
                                break;
                            }
                        }
                        // left에 없으면 right에서 찾기
                        if (idx == -1) {
                            for (int i = 0; i < right.length(); i++) {
                                if (right.charAt(i) == '1') {
                                    right.setCharAt(i, '9');
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            bw.write(left.toString() + right.toString() + '\n');
        }

        bw.flush();
        br.close();
        bw.close();
    }
}