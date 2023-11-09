import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    private static int C, N;
    private static List<List<Double>> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input(br);

        for (List<Double> scores : list) {
            Double sum = scores.stream().reduce(Double::sum).get();
            double avg = getAvg(sum, scores.size());

            bw.write(String.format("%.3f", getPercentage(avg, scores)) + "%\n");
        }

        br.close();
        bw.close();
    }

    private static double getPercentage(double avg, List<Double> scores) {
        int size = (int) scores.stream().filter((score) -> score > avg).count();
        double percentage = (double) size / (double) scores.size();
        percentage *= 100.0;

        return Math.round(percentage * 1000) / 1000.0;
    }

    private static double getAvg(double sum, int n) {
        double avg = sum / (double) n;

        return Math.round(avg * 1000) / 1000.0;
    }

    private static void input(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());

        for (int c = 0; c < C; c++) {
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());

            List<Double> temp = new ArrayList<>();
            for (int n = 0; n < N; n++) {
                temp.add(Double.parseDouble(st.nextToken()));
            }

            list.add(temp);
        }
    }
}
