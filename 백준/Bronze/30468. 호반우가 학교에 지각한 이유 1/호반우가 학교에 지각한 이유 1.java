import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N;
    private static int STR, DEX, INT, LUK;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        int nn = N * 4;
        int sum = STR + DEX + INT + LUK;

        bw.write(String.valueOf(Math.max(0, nn - sum)) + '\n');

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        STR = Integer.parseInt(st.nextToken());
        DEX = Integer.parseInt(st.nextToken());
        INT = Integer.parseInt(st.nextToken());
        LUK = Integer.parseInt(st.nextToken());

        N = Integer.parseInt(st.nextToken());
    }
}
