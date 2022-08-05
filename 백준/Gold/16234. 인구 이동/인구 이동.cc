#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
vector<vector<int>> BOARD;
vector<vector<bool>> visited;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

bool BFS(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> path;

    q.push({y, x});
    visited[y][x] = true;

    int total = BOARD[y][x];
    int cnt = 1;
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
            if (visited[nextY][nextX])
                continue;

            int gap = abs(BOARD[now.first][now.second] - BOARD[nextY][nextX]);

            if (L <= gap && gap <= R) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
                path.emplace_back(nextY, nextX);

                total += BOARD[nextY][nextX];
                cnt++;
            }
        }
    }

    if (path.empty())
        return false;

    int p = total / cnt;
    for (auto &c: path)
        BOARD[c.first][c.second] = p;

    BOARD[y][x] = p;

    return true;
}

int main() {
    cin >> N >> L >> R;

    BOARD = vector<vector<int>>(N, vector<int>(N));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> BOARD[y][x];
        }
    }

    int day = 0;
    while (true) {
        bool move = false;

        visited = vector<vector<bool>>(N, vector<bool>(N, false));

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (visited[y][x])
                    continue;

                if (BFS(y, x))
                    move = true;

            }
        }

        if (!move)
            break;

        day++;
    }

    cout << day << endl;

    return 0;
}