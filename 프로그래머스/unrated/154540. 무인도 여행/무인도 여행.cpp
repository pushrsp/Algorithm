#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

bool Visited[MAX][MAX];
int Y, X, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};

bool InRange(int y, int x) {
    return 0 <= y && y < Y && 0 <= x && x < X;
}

int bfs(int startY, int startX, vector<string> &maps) {
    queue<pair<int, int>> q;
    int ret = maps[startY][startX] - '0';

    Visited[startY][startX] = true;
    q.emplace(startY, startX);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = now.first + DY[i], nx = now.second + DX[i];

            if (!InRange(ny, nx))
                continue;
            if (maps[ny][nx] == 'X')
                continue;
            if (Visited[ny][nx])
                continue;

            Visited[ny][nx] = true;
            q.emplace(ny, nx);
            ret += maps[ny][nx] - '0';
        }
    }

    return ret;
}

vector<int> solution(vector<string> maps) {
    Y = static_cast<int>(maps.size()), X = static_cast<int>(maps[0].size());
    vector<int> answer;

    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            if (!Visited[y][x] && maps[y][x] != 'X')
                answer.push_back(bfs(y, x, maps));
        }
    }

    if (answer.empty())
        return {-1};

    sort(answer.begin(), answer.end());

    return answer;
}