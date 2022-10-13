#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};
int Dp[501][501][4], MaxY, MaxX;
vector<string> Map;

int go(int nowY, int nowX, int dir, int sum) {
    if (Dp[nowY][nowX][dir])
        return sum;

    Dp[nowY][nowX][dir] = 1;

    if (Map[nowY][nowX] == 'R')
        dir = (dir + 3) % 4;
    else if (Map[nowY][nowX] == 'L')
        dir = (dir + 1) % 4;

    int nextY = nowY + deltaY[dir], nextX = nowX + deltaX[dir];
    if (nextY < 0)
        nextY = MaxY - 1;
    if (nextY >= MaxY)
        nextY = 0;
    if (nextX < 0)
        nextX = MaxX - 1;
    if (nextX >= MaxX)
        nextX = 0;

    return go(nextY, nextX, dir, sum + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    Map = grid, MaxY = grid.size(), MaxX = grid[0].size();

    for (int y = 0; y < MaxY; ++y) {
        for (int x = 0; x < MaxX; ++x) {
            for (int i = 0; i < 4; ++i) {
                int n = go(y, x, i, 0);
                if (n != 0)
                    answer.push_back(n);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}