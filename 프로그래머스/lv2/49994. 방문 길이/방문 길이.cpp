#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>

#define MAX 13

using namespace std;

int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
bool Visited[MAX][MAX][4];

bool InRange(int y, int x) {
    return 0 <= y && y <= 10 && 0 <= x && x <= 10;
}

int GetDir(char &dir) {
    if (dir == 'U')
        return 0;
    else if (dir == 'L')
        return 1;
    else if (dir == 'D')
        return 2;
    else
        return 3;
}

int solution(string dirs) {
    int answer = 0;

    int startY = 5, startX = 5;
    for (char &dir: dirs) {
        int d = GetDir(dir);
        int nextY = startY + DY[d], nextX = startX + DX[d];

        if (!InRange(nextY, nextX))
            continue;

        if (!Visited[startY][startX][d] && !Visited[nextY][nextX][(d + 2) % 4]) {
            answer += 1;
            Visited[startY][startX][d] = true;
        }
        
        startY = nextY, startX = nextX;
    }

    return answer;
}