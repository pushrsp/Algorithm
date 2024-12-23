import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;

    static class Pair {
        int weight, price;

        Pair(int weight, int price) {
            this.weight = weight;
            this.price = price;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        List<Pair> pairs = new ArrayList<>();
        int weight, price;
        for (int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            weight = Integer.parseInt(st.nextToken());
            price = Integer.parseInt(st.nextToken());

            pairs.add(new Pair(weight, price));
        }

        Collections.sort(pairs, (o1, o2) -> {
            if (o1.price == o2.price) {
                return -Integer.compare(o1.weight, o2.weight);
            }
            return Integer.compare(o1.price, o2.price);
        });

        int sumWeight = 0, sumPrice = 0, prevPrice = 0;
        for (Pair pair : pairs) {
            if (sumWeight < M) {
                if (prevPrice != pair.price) {
                    sumPrice = pair.price;
                    prevPrice = pair.price;
                } else {
                    sumPrice += pair.price;
                }
            } else {
                if (prevPrice != pair.price && sumPrice >= pair.price) {
                    sumPrice = pair.price;
                    prevPrice = pair.price;
                }
            }
            sumWeight += pair.weight;
        }

        if (sumWeight < M) {
            bw.write(String.valueOf(-1) + '\n');
        } else {
            bw.write(String.valueOf(sumPrice) + '\n');
        }

        br.close();
        bw.close();
    }
}