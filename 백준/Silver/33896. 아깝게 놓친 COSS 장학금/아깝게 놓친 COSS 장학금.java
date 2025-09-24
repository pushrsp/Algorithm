import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        String name;
        int score, risk, cost;

        List<Student> students = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            name = st.nextToken();
            score = Integer.parseInt(st.nextToken());
            risk = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());

            students.add(new Student(name, score, risk, cost));
        }

        Collections.sort(students);

        bw.write(students.get(1).name + '\n');

        br.close();
        bw.close();
    }

    static class Student implements Comparable<Student> {
        String name;
        int score, risk, cost;

        public Student(String name, int score, int risk, int cost) {
            this.name = name;
            this.score = score;
            this.risk = risk;
            this.cost = cost;
        }

        private int score() {
            return (int) Math.floor((score * score * score) / (double) (cost * (risk + 1)));
        }

        @Override
        public int compareTo(Student o) {
            if (score() == o.score()) {
                if (cost == o.cost) {
                    return name.compareTo(o.name);
                }
                return Integer.compare(cost, o.cost);
            }
            return -Integer.compare(score(), o.score());
        }
    }
}