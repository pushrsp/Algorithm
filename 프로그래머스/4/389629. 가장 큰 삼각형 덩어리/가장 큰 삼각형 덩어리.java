import java.util.*;

public class Solution {

    private static int N, M;
    private static int[][] G;
    private final Set<String> visited = new HashSet<>();
    private final List<Triangle> triangles = new ArrayList<>();
    private final int[][] DIR = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
    };

    private String generateVisitedKey(int y, int x) {
        return String.format("%d,%d", y, x);
    }

    private boolean inRange(int y, int x) {
        return 1 <= y && y <= N && 1 <= x && x <= M;
    }

    public int solution(int[][] grid) {
        G = new int[grid.length + 1][grid[0].length + 1];
        N = grid.length;
        M = grid[0].length;

        triangles.add(new Triangle(new int[]{1, 2}, new int[][]{{}, {1, 3}, {1, 2}, {}}));
        triangles.add(new Triangle(new int[]{0, 3}, new int[][]{{0, 3}, {}, {}, {0, 2}}));
        triangles.add(new Triangle(new int[]{0, 1}, new int[][]{{0, 3}, {1, 3}, {}, {}}));
        triangles.add(new Triangle(new int[]{2, 3}, new int[][]{{}, {}, {1, 2}, {0, 2}}));

        for (int y = 0; y < grid.length; y++) {
            for (int x = 0; x < grid[y].length; x++) {
                G[y + 1][x + 1] = grid[y][x];
            }
        }

        Queue<Node> pq = new LinkedList<>();
        Map<Integer, Set<Integer>> m = new HashMap<>();
        m.put(-1, new HashSet<>());
        m.put(1, new HashSet<>());

        m.get(-1).add(0);
        m.get(-1).add(1);

        m.get(1).add(2);
        m.get(1).add(3);

        int answer = 1;
        Set<String> globalVisited = new HashSet<>(); // 전역 방문 체크 추가
        
        for (int y = 1; y <= N; y++) { // y < G.length -> y <= N으로 수정
            for (int x = 1; x <= M; x++) { // x < G[y].length -> x <= M으로 수정
                if (globalVisited.contains(generateVisitedKey(y, x))) { // 이미 처리된 셀은 스킵
                    continue;
                }
                
                visited.clear();
                pq.clear();

                if (G[y][x] == -1) {
                    pq.add(new Node(y, x, 0, 1));
                } else {
                    pq.add(new Node(y, x, 2, 1));
                }

                visited.add(generateVisitedKey(y, x));
                int ret = 0; // ret을 0으로 초기화
                while (!pq.isEmpty()) {
                    Node curr = pq.poll();
                    ret++; // 폴할 때마다 카운트 증가
                    globalVisited.add(generateVisitedKey(curr.y, curr.x)); // 전역 방문 처리
                    
                    for (int i = 0; i < triangles.get(curr.type).dirs.length; i++) {
                        int nextY = curr.y + DIR[triangles.get(curr.type).dirs[i]][0];
                        int nextX = curr.x + DIR[triangles.get(curr.type).dirs[i]][1];

                        if (!inRange(nextY, nextX)) {
                            continue;
                        }

                        int ddir = triangles.get(curr.type).dirs[i];
                        int[] nextTriangle = triangles.get(curr.type).next[ddir];
                        for (int nnext : nextTriangle) {
                            if (m.get(G[nextY][nextX]).contains(nnext) && !visited.contains(generateVisitedKey(nextY, nextX))) {
                                visited.add(generateVisitedKey(nextY, nextX));
                                pq.add(new Node(nextY, nextX, nnext, 0)); // count 파라미터는 사용하지 않음
                            }
                        }
                    }
                }

                answer = Math.max(answer, ret);

                visited.clear();
                pq.clear();

                visited.add(generateVisitedKey(y, x));
                if (G[y][x] == -1) {
                    pq.add(new Node(y, x, 1, 1));
                } else {
                    pq.add(new Node(y, x, 3, 1));
                }

                ret = 0; // ret을 0으로 초기화

                while (!pq.isEmpty()) {
                    Node curr = pq.poll();
                    ret++; // 폴할 때마다 카운트 증가
                    
                    for (int i = 0; i < triangles.get(curr.type).dirs.length; i++) {
                        int nextY = curr.y + DIR[triangles.get(curr.type).dirs[i]][0];
                        int nextX = curr.x + DIR[triangles.get(curr.type).dirs[i]][1];

                        if (!inRange(nextY, nextX)) {
                            continue;
                        }

                        int ddir = triangles.get(curr.type).dirs[i];
                        int[] nextTriangle = triangles.get(curr.type).next[ddir];
                        for (int nnext : nextTriangle) {
                            if (m.get(G[nextY][nextX]).contains(nnext) && !visited.contains(generateVisitedKey(nextY, nextX))) {
                                visited.add(generateVisitedKey(nextY, nextX));
                                pq.add(new Node(nextY, nextX, nnext, 0)); // count 파라미터는 사용하지 않음
                            }
                        }
                    }
                }

                answer = Math.max(answer, ret);

                int temp = 1;
            }
        }

        return answer;
    }

    static class Triangle {
        int[] dirs;
        int[][] next;

        public Triangle(int[] dirs, int[][] next) {
            this.dirs = dirs;
            this.next = next;
        }
    }

    static class Node {
        int y, x, type, count;

        public Node(int y, int x, int type, int count) {
            this.y = y;
            this.x = x;
            this.type = type;
            this.count = count;
        }
    }
}