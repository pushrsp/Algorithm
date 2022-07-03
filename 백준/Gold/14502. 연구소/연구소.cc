#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> MAP, TEMP;
vector<vector<bool>> visited;
vector<pair<int, int>> wall;
priority_queue<int, vector<int>, less<int>> answer;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void BFS() {
    queue<pair<int, int>> q;
    vector<vector<bool>> virus_visited(N, vector<bool>(M, false));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            TEMP[y][x] = MAP[y][x];

            if (TEMP[y][x] == 2) {
                q.emplace(y, x);
                virus_visited[y][x] = true;
            }
        }
    }

    for (auto &w: wall)
        TEMP[w.first][w.second] = 1;

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextY >= N)
                continue;
            if (nextX < 0 || nextX >= M)
                continue;
            if (TEMP[nextY][nextX] != 0)
                continue;
            if (virus_visited[nextY][nextX])
                continue;

            q.emplace(nextY, nextX);
            virus_visited[nextY][nextX] = true;
            TEMP[nextY][nextX] = 2;
        }
    }

    int cnt = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (TEMP[y][x] == 0)
                cnt++;

            TEMP[y][x] = MAP[y][x];
        }
    }

    answer.push(cnt);
}

void perm(int cnt) {
    if (cnt == 3) {
        BFS();
        return;
    } else {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (MAP[y][x] != 0)
                    continue;
                if (visited[y][x])
                    continue;

                wall.emplace_back(y, x);
                visited[y][x] = true;
                perm(cnt + 1);
                wall.pop_back();
                visited[y][x] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    MAP = vector<vector<int>>(N, vector<int>(M));
    TEMP = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> MAP[y][x];
        }
    }

    perm(0);

    cout << answer.top() << endl;
    return 0;
}