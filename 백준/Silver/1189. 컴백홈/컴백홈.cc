#include <iostream>
#include <vector>

using namespace std;

int R, C, K, Answer = 0;
vector<vector<char>> Map;
vector<vector<bool>> Visited;

int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void dfs(int nowY, int nowX, int dist) {
    if (nowY == 0 && nowX == C - 1) {
        if (dist == K - 1)
            Answer++;

        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nextY = nowY + deltaY[i];
        int nextX = nowX + deltaX[i];

        if (nextY < 0 || nextY >= R)
            continue;
        if (nextX < 0 || nextX >= C)
            continue;
        if (Map[nextY][nextX] == 'T')
            continue;
        if (Visited[nextY][nextX])
            continue;

        Visited[nextY][nextX] = true;
        dfs(nextY, nextX, dist + 1);
        Visited[nextY][nextX] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;

    Map = vector<vector<char>>(R, vector<char>(C));
    Visited = vector<vector<bool>>(R, vector<bool>(C, false));

    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> Map[y][x];
        }
    }

    Visited[R - 1][0] = true;
    dfs(R - 1, 0, 0);

    cout << Answer << '\n';
    return 0;
}