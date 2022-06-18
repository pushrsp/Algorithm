#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj, temp;
queue<pair<int, int>> q;
vector<vector<bool>> wall_visited;
vector<int> result;

//위 왼쪽 아래 오른쪽
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

bool cmp(const int &a, const int &b) {
    return a > b;
}

void BFS() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> tt(N, vector<int>(M, 0));
    queue<pair<int, int>> virusQ(q);

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            tt[y][x] = temp[y][x];
        }
    }

    while (!virusQ.empty()) {
        int nowY = virusQ.front().first;
        int nowX = virusQ.front().second;

        virusQ.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextY >= N)
                continue;
            if (nextX < 0 || nextX >= M)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (tt[nextY][nextX] != 0)
                continue;

            visited[nextY][nextX] = true;
            virusQ.push({nextY, nextX});
            tt[nextY][nextX] = 2;
        }
    }

    int cnt = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (tt[y][x] == 0)
                cnt++;
        }
    }

    result.push_back(cnt);
}

void perm_wall(int cnt) {
    if (cnt == 3) {
        BFS();
        return;
    } else {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (wall_visited[y][x])
                    continue;

                if (temp[y][x] == 0) {
                    wall_visited[y][x] = true;
                    temp[y][x] = 1;
                    perm_wall(cnt + 1);
                    temp[y][x] = 0;
                    wall_visited[y][x] = false;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    adj = vector<vector<int>>(N, vector<int>(M, 0));
    temp = vector<vector<int>>(N, vector<int>(M, 0));
    wall_visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> adj[y][x];
            temp[y][x] = adj[y][x];

            if (adj[y][x] == 2)
                q.push({y, x});
        }
    }

    perm_wall(0);
    sort(result.begin(), result.end(), cmp);
    cout << result[0] << endl;

    return 0;
}