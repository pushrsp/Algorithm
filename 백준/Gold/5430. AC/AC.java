import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int T;
    private static int[] EMPTY = {};

    private static int[] getArr(String arr, int len) {
        if (len == 0) {
            return EMPTY;
        } else {
            String input = arr.substring(1, arr.length() - 1);
            String[] elem = input.split(",");
            int[] ret = new int[elem.length];
            for (int i = 0; i < elem.length; i++) {
                ret[i] = Integer.parseInt(elem[i]);
            }
            return ret;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            int[] arr = getArr(br.readLine(), n);

            int start = 0, end = n;
            boolean reversed = false;
            boolean error = false;
            for (int i = 0; i < p.length(); i++) {
                if (arr.length == 0 && p.charAt(i) == 'D') {
                    bw.write("error\n");
                    error = true;
                    break;
                }
                if (p.charAt(i) == 'R') {
                    reversed = !reversed;
                } else {
                    if (start == end) {
                        bw.write("error\n");
                        error = true;
                        break;
                    }

                    if (reversed) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }

            if (!error) {
                bw.write('[');
                if (arr.length > 0 && start != end) {
                    if (!reversed) {
                        for (int i = start; i < end - 1; i++) {
                            bw.write(String.valueOf(arr[i]) + ',');
                        }
                        bw.write(String.valueOf(arr[end - 1]));
                    } else {
                        for (int i = end - 1; i > start; i--) {
                            bw.write(String.valueOf(arr[i]) + ',');
                        }
                        bw.write(String.valueOf(arr[start]));
                    }
                }
                bw.write("]\n");
            }
        }

        br.close();
        bw.close();
    }
}