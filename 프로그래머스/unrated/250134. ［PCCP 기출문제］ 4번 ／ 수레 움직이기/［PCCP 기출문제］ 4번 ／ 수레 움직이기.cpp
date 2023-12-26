#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

vector<vector<int>> Maze;
int N, M, YY1, XX1, YY2, XX2, Ret = INT32_MAX;
int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
bool Visited[5][5][2];

bool in_range(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

bool is_red_done(int y1, int x1) {
    return y1 == YY1 && x1 == XX1;
}

bool is_blue_done(int y2, int x2) {
    return y2 == YY2 && x2 == XX2;
}

bool is_both_done(int y1, int x1, int y2, int x2) {
    return is_red_done(y1, x1) && is_blue_done(y2, x2);
}

void go(int y1, int x1, int y2, int x2, int turn, int count) {
    if(!in_range(y1, x1) || !in_range(y2, x2))
        return;
    
    if(is_both_done(y1, x1, y2, x2)) {
        int offset = 0;
        if(count % 2)
            offset = 1;
        
        Ret = min(Ret, (count / 2) + offset);
        return;
    }

    if(turn == 0) { //빨강 차례
        if(is_red_done(y1, x1)) {
            go(y1, x1, y2, x2, (turn + 1) % 2, count + 1);
        } else {
            for(int i = 0; i < 4; i++) {
                int nextY = y1 + DY[i], nextX = x1 + DX[i];
                
                if(!in_range(nextY, nextX)) //범위 체크
                    continue;
                if(nextY == y2 && nextX == x2) //같은 칸 x
                    continue;
                if(Maze[nextY][nextX] == 5) //벽
                    continue;
                if(Visited[nextY][nextX][turn]) //방문
                    continue;
                
                Visited[nextY][nextX][turn] = true;
                go(nextY, nextX, y2, x2, (turn + 1) % 2, count + 1);
                Visited[nextY][nextX][turn] = false;
            }
        }
    } else { //파랑 차례
        if(is_blue_done(y2, x2)) {
            go(y1, x1, y2, x2, (turn + 1) % 2, count + 1);
        } else {
            for(int i = 0; i < 4; i++) {
                int nextY = y2 + DY[i], nextX = x2 + DX[i];
                
                if(!in_range(nextY, nextX))
                    continue;
                if(nextY == y1 && nextX == x1)
                    continue;
                if(Maze[nextY][nextX] == 5)
                    continue;
                if(Visited[nextY][nextX][turn])
                    continue;
                
                Visited[nextY][nextX][turn] = true;
                go(y1, x1, nextY, nextX, (turn + 1) % 2, count + 1);
                Visited[nextY][nextX][turn] = false;
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    N = maze.size();
    M = maze[0].size();
    Maze = vector<vector<int>>(N, vector<int>(M));
    
    int y1, x1, y2, x2;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(maze[y][x] == 1)
                y1 = y, x1 = x;
            else if(maze[y][x] == 2)
                y2 = y, x2 = x;
            else if(maze[y][x] == 3)
                YY1 = y, XX1 = x;
            else if(maze[y][x] == 4)
                YY2 = y, XX2 = x;
            else if(maze[y][x] == 5)
                Maze[y][x] = 5;
        }
    }
    
    Visited[y1][x1][0] = true;
    Visited[y2][x2][1] = true;
    go(y1, x1, y2, x2, 0, 0);
    
    int a1 = Ret;
    
    ::memset(Visited, 0, sizeof(Visited));
    
    Visited[y1][x1][0] = true;
    Visited[y2][x2][1] = true;
    
    go(y1, x1, y2, x2, 1, 0);
    
    int a2 = Ret;
    
    int ret = min(a1, a2);
    if(ret == INT32_MAX)
        return 0;
    
    return ret;
}