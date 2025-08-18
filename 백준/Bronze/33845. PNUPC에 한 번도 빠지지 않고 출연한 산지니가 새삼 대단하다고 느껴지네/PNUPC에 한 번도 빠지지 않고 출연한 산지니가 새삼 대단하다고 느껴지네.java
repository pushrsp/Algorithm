import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s1 = br.readLine();
        String s2 = br.readLine();

        Set<Character> s = new HashSet<>();
        for (int i = 0; i < s1.length(); i++) {
            s.add(s1.charAt(i));
        }

        for (int i = 0; i < s2.length(); i++) {
            if (!s.contains(s2.charAt(i))) {
                bw.write(String.valueOf(s2.charAt(i)));
            }
        }

        bw.write('\n');

        br.close();
        bw.close();
    }
}