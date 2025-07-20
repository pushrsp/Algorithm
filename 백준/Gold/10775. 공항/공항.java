import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    private static int G, P;
    private static boolean[] DP = new boolean[100_001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        TreeSet<Integer> set = new TreeSet<>();
        G = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= G; i++) {
            set.add(i);
        }

        st = new StringTokenizer(br.readLine());

        P = Integer.parseInt(st.nextToken());

        List<Integer> airplanes = new ArrayList<>();

        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            airplanes.add(Integer.parseInt(st.nextToken()));
        }

        int ret = 0;
        for (Integer airplane : airplanes) {
            Integer index = set.lower(airplane + 1);
            if (index == null) {
                break;
            } else {
                ret++;
                set.remove(index);
            }
        }
        
        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }
}