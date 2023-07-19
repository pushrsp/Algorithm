import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    private static int B, N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        B = Integer.parseInt(st.nextToken());

        List<String> lowList = new ArrayList<>();
        for (int b = 0; b < B; b++) {
            st = new StringTokenizer(br.readLine());
            lowList.add(st.nextToken());
        }

        List<String> highList = new ArrayList<>();
        for (int b = 0; b < B; b++) {
            st = new StringTokenizer(br.readLine());
            highList.add(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            String data = st.nextToken();

            int low = 0;
            for(String l : lowList) {
                for (int i = 0; i < data.length() - l.length() + 1; i++) {
                    if(l.equals(data.substring(i, i + l.length()))) {
                        low++;
                    }
                }
            }

            int high = 0;
            for(String h : highList) {
                for (int i = 0; i < data.length() - h.length() + 1; i++) {
                    if(h.equals(data.substring(i, i + h.length()))) {
                        high++;
                    }
                }
            }

            if(low == high) {
                bw.write("GOOD" + '\n');
            } else if(low > high) {
                bw.write("HIGH " + String.valueOf(low - high) + '\n');
            } else {
                bw.write("LOW " + String.valueOf(high - low) + '\n');
            }
        }

        bw.close();
        br.close();
    }
}
