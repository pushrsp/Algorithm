import java.awt.*;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static int N;
    private static final Map<String, String> MAP = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        MAP.put("@", "a");
        MAP.put("[", "c");
        MAP.put("!", "i");
        MAP.put(";", "j");
        MAP.put("^", "n");
        MAP.put("0", "o");
        MAP.put("7", "t");
        MAP.put("\\'", "v");
        MAP.put("\\\\'", "w");

        int s = 'a', e = 'z';
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            StringBuilder ret = new StringBuilder();
            StringBuilder sb = new StringBuilder();

            int count = 0, total = 0, i = 0;
            while (i < str.length()) {
                if(s <= str.charAt(i) && str.charAt(i) <= e) {
                    ret.append(str.charAt(i));
                    total++;
                } else {
                    if(MAP.containsKey(String.valueOf(str.charAt(i)))) {
                        ret.append(MAP.get(String.valueOf(str.charAt(i))));
                        total++;
                        count++;
                    } else {
                        sb.append(str.charAt(i));

                        if(MAP.containsKey(sb.toString())) {
                            ret.append(MAP.get(sb.toString()));
                            total++;
                            count++;
                            sb = new StringBuilder();
                        }
                    }
                }

                i++;
            }

            if(sb.length() > 0) {
                if(MAP.containsKey(sb.toString())) {
                    ret.append(MAP.get(sb.toString()));
                    total++;
                    count++;
                }
            }

            if(count * 2 >= total) {
                bw.write("I don't understand" + '\n');
            } else {
                bw.write(ret.toString() + '\n');
            }
        }

        bw.close();
        br.close();
    }
}
