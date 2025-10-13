import java.io.*;
import java.util.*;

public class Main {

    private static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            numbers.add(i);
        }

        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < (N / 2) + (N % 2); i++) {
            stack.add(numbers.get(i));
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = (N / 2) + (N % 2); i < N; i++) {
            queue.add(numbers.get(i));
        }

        List<Integer> answer = new ArrayList<>();
        while (!stack.isEmpty() && !queue.isEmpty()) {
            answer.add(stack.pop());
            answer.add(queue.poll());
        }

        while (!stack.isEmpty()) {
            answer.add(stack.pop());
        }

        for (int i = 0; i < answer.size() - 1; i++) {
            bw.write(String.valueOf(answer.get(i)) + ' ');
        }

        bw.write(String.valueOf(answer.get(answer.size() - 1)) + '\n');

        br.close();
        bw.close();
    }
}