import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    private static int N;
    private static int[] Ans;
    private static List<Lecture> Lectures = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        Collections.sort(Lectures);

        PriorityQueue<Room> pq = new PriorityQueue<>();

        int num = 1;
        for(Lecture lecture: Lectures) {
            if(pq.isEmpty()) {
                Ans[lecture.i] = num;
                pq.add(new Room(num++, lecture.end));
            } else {
                if(pq.peek().time > lecture.start) {
                    Ans[lecture.i] = num;
                    pq.add(new Room(num++, lecture.end));
                } else {
                    Room room = pq.poll();
                    room.time = lecture.end;
                    Ans[lecture.i] = room.num;

                    pq.add(room);
                }
            }
        }

        bw.write(String.valueOf(pq.size()) + '\n');
        for (int i = 1; i <= N; i++) {
            bw.write(String.valueOf(Ans[i]) + '\n');
        }

        br.close();
        bw.close();
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Ans = new int[N + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            Lecture lecture = new Lecture();

            lecture.i = Integer.parseInt(st.nextToken());
            lecture.start = Long.parseLong(st.nextToken());
            lecture.end = Long.parseLong(st.nextToken());

            Lectures.add(lecture);
        }
    }

    static class Room implements Comparable<Room> {
        public int num;
        public long time;

        public Room(int num, long time) {
            this.num = num;
            this.time = time;
        }

        @Override
        public int compareTo(Room o) {
            return Long.compare(time, o.time);
        }
    }

    static class Lecture implements Comparable<Lecture> {
        public int i;
        public long start, end;

        @Override
        public int compareTo(Lecture o) {
            return Long.compare(start, o.start);
        }
    }
}
