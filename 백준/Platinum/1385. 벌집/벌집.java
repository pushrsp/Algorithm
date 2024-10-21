import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static int A, B, SY, SX;
    private static int[][] G = new int[1501][1501];
    private static int[] V = new int[1000001];
    private static int[] DY = {-1, 0, 1, 1, 0, -1};
    private static int[] DX = {0, 1, 1, 0, -1, -1};

    private static void go() {
        int curY = 750, curX = 750;
        int n = 1, l = 1;
        G[curY][curX] = 1;
        while (true) {
            for (int d = 0; d < 6; d++) {
                for (int i = 0; i < (d == 1 ? l - 1 : l); i++) {
                    int nextY = curY + DY[d];
                    int nextX = curX + DX[d];
                    G[nextY][nextX] = ++n;
                    if (n == A) {
                        SY = nextY;
                        SX = nextX;
                    }
                    if (n == 1000000) {
                        return;
                    }
                    curY = nextY;
                    curX = nextX;
                }
            }
            l++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        go();

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{SY, SX});
        V[G[SY][SX]] = A;

        while (!q.isEmpty()) {
            int currY = q.peek()[0];
            int currX = q.peek()[1];
            q.poll();

            if (G[currY][currX] == B) {
                break;
            }

            for (int d = 0; d < 6; d++) {
                int nextY = currY + DY[d];
                int nextX = currX + DX[d];
                if (G[nextY][nextX] == 0 || V[G[nextY][nextX]] != 0) {
                    continue;
                }
                V[G[nextY][nextX]] = G[currY][currX];
                q.add(new int[]{nextY, nextX});
            }
        }

        Stack<Integer> stack = new Stack<>();
        int curr = B;
        while (curr != A) {
            stack.add(curr);
            curr = V[curr];
        }

        stack.add(A);

        while (stack.size() != 1) {
            bw.write(String.valueOf(stack.pop()) + ' ');
        }

        bw.write(String.valueOf(stack.pop()) + '\n');

        br.close();
        bw.close();
    }
}