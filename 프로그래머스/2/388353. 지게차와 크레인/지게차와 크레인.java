import java.util.*;

class Solution {
    private int[][] G = new int[53][53];
    private int[] DY = {-1, 0, 1, 0};
    private int[] DX = {0, -1, 0, 1};
    private int Y, X;
    
    private boolean inRange(int y, int x) {
        return 0 <= y && y <= Y + 1 && 0 <= x && x <= X + 1;
    }
    
    private void pickOuterLine(int c) {
        boolean[][] V = new boolean[53][53];
        List<Pair> pairs = new ArrayList<>();
        
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0, 0));
        while(!q.isEmpty()) {
            Pair curr = q.poll();
            
            for(int i = 0; i < 4; i++) {
                int nextY = curr.y + DY[i];
                int nextX = curr.x + DX[i];
                
                if(!inRange(nextY, nextX)) {
                    continue;
                }
                
                if(G[nextY][nextX] == c) {
                    pairs.add(new Pair(nextY, nextX));
                } else if(G[nextY][nextX] == 0 && !V[nextY][nextX]) {
                    V[nextY][nextX] = true;
                    q.add(new Pair(nextY, nextX));
                }
            }
        }
        
        for(Pair pair: pairs) {
            G[pair.y][pair.x] = 0;
        } 
    }
    
    private void pickAll(int c) {
        List<Pair> pairs = new ArrayList<>();
        for(int y = 1; y <= Y; y++) {
            for(int x = 1; x <= X; x++) {
                if(G[y][x] == c) {
                    pairs.add(new Pair(y, x));
                }
            }
        }
        
        for(Pair pair: pairs) {
            G[pair.y][pair.x] = 0;
        }
    }
    
    public int solution(String[] storage, String[] requests) {
        Y = storage.length;
        X = storage[0].length();
        
        for(int y = 0; y < storage.length; y++) {
            for(int x = 0; x < storage[y].length(); x++) {
                G[y + 1][x + 1] = storage[y].charAt(x) - 'A';
                G[y + 1][x + 1]++;
            }
        }
        
        for(String request: requests) {
            if(request.length() == 1) {
                pickOuterLine(request.charAt(0) - 'A' + 1);
            } else {
                pickAll(request.charAt(0) - 'A' + 1);
            }
        }
        
        int answer = 0;
        for(int y = 1; y <= Y; y++) {
            for(int x = 1; x <= X; x++) {
                if(G[y][x] > 0) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
    
    static class Pair {
        int y, x;
        
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}