import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static int Q;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Q = Integer.parseInt(st.nextToken());

        Stack<Long> stack = new Stack<>();
        Stack<Command> history = new Stack<>();

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int oper = Integer.parseInt(st.nextToken());

            if (oper == 1) {
                long value = Long.parseLong(st.nextToken());
                stack.add(value);
                history.add(new Command(2, -1));
            } else if (oper == 2) {
                long value = stack.pop();
                history.add(new Command(1, value));
            } else if (oper == 3) {
                int j = Integer.parseInt(st.nextToken());
                while (j-- > 0) {
                    Command command = history.pop();
                    if (command.oper == 1) {
                        stack.push(command.value);
                    } else {
                        stack.pop();
                    }
                }
            } else if (oper == 4) {
                bw.write(String.valueOf(stack.size()) + '\n');
            } else if (oper == 5) {
                if (stack.isEmpty()) {
                    bw.write(String.valueOf(-1) + '\n');
                } else {
                    bw.write(String.valueOf(stack.peek()) + '\n');
                }
            }
        }

        br.close();
        bw.close();
    }

    static class Command {
        int oper;
        long value;

        public Command(int oper, long value) {
            this.oper = oper;
            this.value = value;
        }
    }
}