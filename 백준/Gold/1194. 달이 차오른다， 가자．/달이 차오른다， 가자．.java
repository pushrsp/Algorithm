import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int MAX = 1_000_000;
    private static int N, M;
    private static int[][] DIR = {
            {-1, 0}, // 위
            {0, -1}, // 왼
            {1, 0}, // 아
            {0, 1}, // 오
    };
    private static boolean[][][] V = new boolean[51][51][1 << 6];
    private static char[][] G = new char[51][51];

    private static boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    private static boolean hasKey(int key, char gate) {
        int gateIndex = 1 << (gate - 'A');
        return (key & gateIndex) > 0;
    }

    private static boolean isKey(char c) {
        return c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f';
    }

    private static boolean isGate(char c) {
        return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F';
    }

    private static boolean isWall(char c) {
        return c == '#';
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int startY = 0, startX = 0;
        for (int y = 0; y < N; y++) {
            String s = br.readLine();
            for (int x = 0; x < M; x++) {
                G[y + 1][x + 1] = s.charAt(x);
                if (s.charAt(x) == '0') {
                    startY = y + 1;
                    startX = x + 1;
                    G[y + 1][x + 1] = '.';
                }
            }
        }

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(startY, startX, 0, 0));
        V[startY][startX][0] = true;

        int ret = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            Node curr = q.poll();
            int curY = curr.y;
            int curX = curr.x;
            int key = curr.key;

            if (G[curY][curX] == '1') {
                ret = Math.min(ret, curr.ret);
                continue;
            }

            for (int[] d : DIR) {
                int nextY = curY + d[0];
                int nextX = curX + d[1];

                if (!inRange(nextY, nextX) || isWall(G[nextY][nextX])) {
                    continue;
                }

                if (isKey(G[nextY][nextX])) {
                    if (!V[nextY][nextX][key | (1 << (G[nextY][nextX] - 'a'))]) {
                        V[nextY][nextX][key | (1 << (G[nextY][nextX] - 'a'))] = true;
                        q.add(new Node(nextY, nextX, curr.ret + 1, key | (1 << (G[nextY][nextX] - 'a'))));
                    }
                } else if (isGate(G[nextY][nextX])) {
                    if (hasKey(key, G[nextY][nextX]) && !V[nextY][nextX][key]) {
                        V[nextY][nextX][key] = true;
                        q.add(new Node(nextY, nextX, curr.ret + 1, key));
                    }
                } else {
                    if (!V[nextY][nextX][key]) {
                        V[nextY][nextX][key] = true;
                        q.add(new Node(nextY, nextX, curr.ret + 1, key));
                    }
                }
            }
        }

        if (ret == Integer.MAX_VALUE) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(ret) + '\n');
        }

        br.close();
        bw.close();
    }

    static class Node {
        int y, x, ret, key;

        Node(int y, int x, int ret, int key) {
            this.y = y;
            this.x = x;
            this.ret = ret;
            this.key = key;
        }
    }
}