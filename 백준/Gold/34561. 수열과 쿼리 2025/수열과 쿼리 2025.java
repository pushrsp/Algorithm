import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static int[] A = new int[300_001];
    private static int N, M;
    private static int[] parent = new int[300_001];
    private static int[] numbers = new int[300_001];

    private static int go(int number) {
        if (parent[number] == number) {
            return number;
        } else {
            return parent[number] = go(parent[number]);
        }
    }

    private static void union(int number, int i1, int i2) {
        i1 = go(i1);
        i2 = go(i2);

        if (i1 == i2) {
            return;
        } else if (i1 < i2) {
            parent[i2] = i1;
            numbers[number] = i1;
            A[i1] = number;
        } else {
            parent[i1] = i2;
            numbers[number] = i2;
            A[i2] = number;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            if (numbers[A[i]] == 0) {
                numbers[A[i]] = i;
            } else {
                union(A[i], i, numbers[A[i]]);
            }
        }

        M = Integer.parseInt(br.readLine());

        int x, y, z;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            if (x == 1) {
                z = Integer.parseInt(st.nextToken());
                if (numbers[y] == 0) {
                    continue;
                }

                if (numbers[z] != 0) {
                    union(z, numbers[y], numbers[z]);
                    numbers[y] = 0;
                } else {
                    numbers[z] = numbers[y];
                    numbers[y] = 0;
                    A[numbers[z]] = z;
                }
            } else {
                bw.write(String.valueOf(A[go(y)]) + '\n');
            }
        }

        br.close();
        bw.close();
    }
}