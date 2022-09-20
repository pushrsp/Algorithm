#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int y, x, dist;
};

int N, answer = INT32_MAX;
vector<vector<int>> MAP;
vector<vector<bool>> visited;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void mark_island(int nowY, int nowX, int idx) {
    queue<pair<int, int>> q;

    q.push({nowY, nowX});
    visited[nowY][nowX] = true;
    MAP[nowY][nowX] = idx;

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.first + deltaY[i];
            int nextX = now.second + deltaX[i];

            if (nextY < 0 || nextY >= N)
                continue;
            if (nextX < 0 || nextX >= N)
                continue;
            if (MAP[nextY][nextX] == 0)
                continue;
            if (visited[nextY][nextX])
                continue;

            visited[nextY][nextX] = true;
            MAP[nextY][nextX] = idx;
            q.push({nextY, nextX});
        }
    }
}

void connect_bridge(int islandIdx) {
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    queue<Node> q;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (MAP[y][x] == islandIdx) {
                visited[y][x] = true;
                q.push({y, x, 0});
            }
        }
    }

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];

            if (nextY < 0 || nextY >= N)
                continue;
            if (nextX < 0 || nextX >= N)
                continue;

            if (MAP[nextY][nextX] != 0 && MAP[nextY][nextX] != islandIdx) {
                answer = min(answer, now.dist);
                return;
            }

            if (MAP[nextY][nextX] == 0 && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX, now.dist + 1});
            }
        }
    }
}

int main() {
    cin >> N;
    MAP = vector<vector<int>>(N, vector<int>(N, 0));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> MAP[y][x];
        }
    }

    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    int idx = 1;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (MAP[y][x] == 0)
                continue;
            if (visited[y][x])
                continue;

            mark_island(y, x, idx);
            idx++;
        }
    }

    for (int i = 1; i < idx; ++i)
        connect_bridge(i);

    cout << answer << endl;
    return 0;
}