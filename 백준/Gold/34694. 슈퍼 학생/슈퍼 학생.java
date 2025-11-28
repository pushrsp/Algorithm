import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int A, B, W, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        List<Long> flexible = new ArrayList<>();
        for (int i = 0; i < A; i++) {
            flexible.add(Long.parseLong(br.readLine()));
        }

        List<Schedule> schedules = new ArrayList<>();
        for (int i = 1; i <= W; i++) {
            st = new StringTokenizer(br.readLine());

            Schedule schedule = new Schedule();
            schedule.floor = i;
            for (int j = 0; j < B; j++) {
                long floor = Long.parseLong(st.nextToken());
                schedule.max = Math.max(schedule.max, floor);
                schedule.size++;
            }
            schedules.add(schedule);
        }

        flexible.sort(Collections.reverseOrder());
        schedules.sort((o1, o2) -> -Long.compare(o1.max, o2.max));

        int index = 0;
        for (Long l : flexible) {
            schedules.get(index).max = Math.max(schedules.get(index).max, l);
            schedules.get(index).size++;
            if (schedules.get(index).size == M) {
                index++;
            }
        }

        long ret = 0;
        for (Schedule schedule : schedules) {
            ret += 2 * Math.abs(1 - schedule.max);
        }
        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    static class Schedule {
        int size, floor;
        long max;
    }
}