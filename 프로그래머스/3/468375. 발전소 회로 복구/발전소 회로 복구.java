import java.util.*;

class Solution {

    private int Y, X;
    private Map<Integer, Integer> panelFloor = new HashMap<>();
    private Map<Integer, Panel> panelPosition = new HashMap<>();
    private int[][] dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    private boolean[] activated = new boolean[21];
    private int[] elevator = new int[2];
    private boolean[][] G = new boolean[101][101];

    private boolean allActivated(int panelSize, int visited) {
        int on = 0;
        for (int i = 0; i < panelSize; i++) {
            if ((visited & (1 << i)) != 0) {
                on += 1;
            }
        }
        return on == panelSize;
    }

    public int solution(int h, String[] grid, int[][] panels, int[][] seqs) {
        Y = grid.length;
        X = grid[0].length();
        for (int i = 0; i < panels.length; i++) {
            int no = i, floor = panels[i][0], y = panels[i][1], x = panels[i][2];
            panelFloor.put(no, floor);
            panelPosition.put(no, new Panel(no, floor, y, x));
        }

        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (grid[y].charAt(x) == '@') {
                    elevator[0] = y + 1;
                    elevator[1] = x + 1;
                }

                G[y + 1][x + 1] = grid[y].charAt(x) != '#';
            }
        }

        int k = panels.length;
        int[][] dp = new int[k][1 << k];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // 패널 간 이동 비용 미리 계산
        int[][] moveCost = new int[k][k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i != j) {
                    moveCost[i][j] = bfs(j, panelPosition.get(i).y, panelPosition.get(i).x, panelFloor.get(i));
                }
            }
        }

        // {lastPanel, currDist, visited}
        PriorityQueue<int[]> q = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));
        q.add(new int[]{0, 0, 0});
        dp[0][0] = 0;

        int answer = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int lastPanel = curr[0], currDist = curr[1], visited = curr[2];

            if (allActivated(panels.length, visited)) {
                answer = Math.min(answer, currDist);
                continue;
            }

            int[] indegree = new int[panels.length];
            for (int[] seq : seqs) {
                indegree[seq[1] - 1] += 1;
            }

            for (int i = 0; i < panels.length; i++) {
                if ((visited & (1 << i)) != 0) {
                    for (int[] seq : seqs) {
                        if (seq[0] - 1 == i) {
                            indegree[seq[1] - 1] -= 1;
                        }
                    }
                }
            }

            List<Integer> candidates = new ArrayList<>();
            for (int i = 0; i < panels.length; i++) {
                if (indegree[i] == 0 && (visited & (1 << i)) == 0) {
                    candidates.add(i);
                }
            }

            for (int panelNo : candidates) {
                int totalDist = currDist + moveCost[lastPanel][panelNo];
                int newVisited = visited | (1 << panelNo);

                if (totalDist < dp[panelNo][newVisited]) {
                    dp[panelNo][newVisited] = totalDist;
                    q.add(new int[]{panelNo, totalDist, newVisited});
                }
            }
        }

        return answer;
    }

    private boolean inRange(int y, int x) {
        return 1 <= y && y <= Y && 1 <= x && x <= X;
    }

    private int di(int currY, int currX, int destY, int destX) {
        int[][] dist = new int[Y + 1][X + 1];
        for (int y = 0; y <= Y; y++) {
            Arrays.fill(dist[y], Integer.MAX_VALUE);
        }

        dist[currY][currX] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[0], o2[0]));
        pq.add(new int[]{0, currY, currX});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0], y = curr[1], x = curr[2];

            for (int[] dir : dirs) {
                int nextY = y + dir[0], nextX = x + dir[1], nextD = d + 1;
                if (!inRange(nextY, nextX)) {
                    continue;
                }

                if (!G[nextY][nextX]) {
                    continue;
                }

                if (nextD < dist[nextY][nextX]) {
                    dist[nextY][nextX] = nextD;
                    pq.add(new int[]{nextD, nextY, nextX});
                }
            }
        }

        return dist[destY][destX];
    }

    private int bfs(int panelNo, int currY, int currX, int currFloor) {
        int ret = 0;
        if (currFloor != panelFloor.get(panelNo)) {
            ret += di(currY, currX, elevator[0], elevator[1]) + Math.abs(currFloor - panelFloor.get(panelNo));
            currY = elevator[0];
            currX = elevator[1];
        }

        return ret + di(currY, currX, panelPosition.get(panelNo).y, panelPosition.get(panelNo).x);
    }

    static class Panel {
        int no, floor, y, x;

        Panel(int no, int floor, int y, int x) {
            this.no = no;
            this.floor = floor;
            this.y = y;
            this.x = x;
        }
    }
}