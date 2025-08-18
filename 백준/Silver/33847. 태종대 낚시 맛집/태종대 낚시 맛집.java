import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static int N, C;

    private static int simulate(List<Fish> fishes, int initialBait) {
        List<Fish> availableFishes = new ArrayList<>(fishes);
        int remainingBait = initialBait;
        int totalRevenue = 0;

        while (remainingBait > 0 && !availableFishes.isEmpty()) {
            Fish bestFish = null;
            int bestIndex = -1;

            for (int i = 0; i < availableFishes.size(); i++) {
                Fish fish = availableFishes.get(i);
                if (fish.x <= remainingBait) {
                    if (bestFish == null || fish.s > bestFish.s) {
                        bestFish = fish;
                        bestIndex = i;
                    }
                }
            }

            if (bestFish == null) break;

            availableFishes.remove(bestIndex);
            remainingBait -= bestFish.x;
            totalRevenue += bestFish.w;
        }

        return totalRevenue - (initialBait * C);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());

        List<Fish> fishes = new ArrayList<>();
        int x, s, w;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            fishes.add(new Fish(x, s, w));
        }

        int ret = 0;
        for (int baitCount = 0; baitCount <= 10000; baitCount++) {
            ret = Math.max(ret, simulate(fishes, baitCount));
        }

        bw.write(String.valueOf(ret) + '\n');

        br.close();
        bw.close();
    }

    static class Fish {
        int x, s, w;

        public Fish(int x, int s, int w) {
            this.x = x;
            this.s = s;
            this.w = w;
        }
    }
}