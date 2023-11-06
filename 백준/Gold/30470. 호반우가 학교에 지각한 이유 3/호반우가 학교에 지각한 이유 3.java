import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N;
    private static List<Cmd> Commands = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        Stack<Pair> stack = new Stack<>();
        for (Cmd command : Commands) {
            int cmd = command.cmd;

            if(cmd == 1) {
                stack.push(new Pair(command.h, 1));
            } else {
                if(!stack.isEmpty()) {
                    long damage = Math.max(0, stack.peek().height - command.h);
                    int count = 0;

                    while (!stack.isEmpty() && stack.peek().height >= damage) {
                        Pair pair = stack.pop();
                        count += pair.count;
                    }

                    if(count > 0) {
                        stack.push(new Pair(damage, count));
                    }
                }
            }
        }

        long ret = 0;
        while (!stack.isEmpty()) {
            Pair pair = stack.pop();
            ret += pair.height * pair.count;
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            Commands.add(new Cmd(Integer.parseInt(st.nextToken()), Long.parseLong(st.nextToken())));
        }
    }

    static class Pair {
        public long height;
        public int count;

        public Pair(long height, int count) {
            this.height = height;
            this.count = count;
        }
    }

    static class Cmd {
        public int cmd;
        public long h;

        public Cmd(int cmd, long h) {
            this.cmd = cmd;
            this.h = h;
        }
    }
}
