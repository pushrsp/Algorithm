import java.io.*;
import java.util.*;

public class Main {

    private static int N, Q, K;

    static class Cmd {
        int cmd, p;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int lastOne = Q + 1;
        List<Cmd> cmds = new ArrayList<>();
        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            Cmd cmd = new Cmd();
            cmd.cmd = Integer.parseInt(st.nextToken());
            if (cmd.cmd == 0) {
                cmd.p = Integer.parseInt(st.nextToken());
            }
            cmds.add(cmd);
            if (cmd.cmd == 1) {
                lastOne = q;
            }
        }

        boolean reversed = true;
        Deque<Integer> ans = new ArrayDeque<>();
        if (lastOne == Q + 1) {
            for (int q = 0; q < Q; q++) {
                if (cmds.get(q).cmd == 0) {
                    if (reversed) {
                        ans.addFirst(cmds.get(q).p);
                    } else {
                        ans.addLast(cmds.get(q).p);
                    }
                } else {
                    reversed = !reversed;
                }
            }
        } else {
            List<Integer> temp = new ArrayList<>();
            for (int q = 0; q < Q; q++) {
                if (q < lastOne) {
                    if (cmds.get(q).cmd == 0) {
                        temp.add(cmds.get(q).p);
                    } else if (cmds.get(q).cmd == 2) {
                        reversed = !reversed;
                    }
                } else if (q == lastOne) {
                    Collections.sort(temp);
                    for (int t : temp) {
                        ans.addLast(t);
                    }
                    reversed = true;
                } else {
                    if (cmds.get(q).cmd == 0) {
                        if (reversed) {
                            ans.addFirst(cmds.get(q).p);
                        } else {
                            ans.addLast(cmds.get(q).p);
                        }
                    } else {
                        reversed = !reversed;
                    }
                }
            }
        }

        int k = 0;
        while (!ans.isEmpty() && k < K - 1) {
            if (reversed) {
                ans.pollFirst();
            } else {
                ans.pollLast();
            }
            k++;
        }

        if (reversed) {
            bw.write(String.valueOf(ans.getFirst()) + '\n');
        } else {
            bw.write(String.valueOf(ans.getLast()) + '\n');
        }
        br.close();
        bw.close();
    }
}