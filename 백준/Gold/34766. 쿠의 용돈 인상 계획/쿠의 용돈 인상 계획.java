import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T, D, K;
    private static String N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            D = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            N = br.readLine();

            int latestIndex = 0;
            for (int i = 0; i < D; i++) {
                if (((int) N.charAt(i) - '0') * 9 > 10) {
                    latestIndex = i;
                }
            }

            StringBuilder left = new StringBuilder(N.substring(0, latestIndex + 1));
            StringBuilder right = new StringBuilder(N.substring(latestIndex + 1));

            while (K-- > 0) {
                int index = -1;
                for (int i = right.length() - 1; i >= 0; i--) {
                    if (right.charAt(i) - '0' > 1) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    int result = ((int) right.charAt(index) - '0') * 9;
                    right.setCharAt(index, String.valueOf(result).charAt(0));
                    right.insert(index + 1, String.valueOf(result).charAt(1));
                } else {
                    for (int i = left.length() - 1; i >= 0; i--) {
                        if (left.charAt(i) - '0' > 1) {
                            index = i;
                            break;
                        }
                    }

                    if (index != -1) {
                        int result = ((int) left.charAt(index) - '0') * 9;
                        left.setCharAt(index, String.valueOf(result).charAt(0));
                        left.insert(index + 1, String.valueOf(result).charAt(1));
                    } else {
                        for (int i = 0; i < left.length(); i++) {
                            if (left.charAt(i) == '1') {
                                index = i;
                                break;
                            }
                        }

                        if (index != -1) {
                            left.setCharAt(index, '9');
                        } else {
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

            bw.write(left + right.toString() + '\n');
        }

        br.close();
        bw.close();
    }
}