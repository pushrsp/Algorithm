import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());

        while (true) {
            String s1 = br.readLine();
            if ("end".equals(s1)) {
                break;
            } else if ("animal".equals(s1)) {
                bw.write("Panthera tigris\n");
            } else if ("tree".equals(s1)) {
                bw.write("Pinus densiflora \n");
            } else {
                bw.write("Forsythia koreana\n");
            }
        }

        br.close();
        bw.close();
    }
}