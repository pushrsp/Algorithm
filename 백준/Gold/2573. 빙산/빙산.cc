#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> adj, adj_temp;
queue<pair<int, int>> q, q_temp;
vector<vector<bool>> visited;
//위 왼쪽 아래 오른쪽
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

//melt
void BFS() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = y + deltaY[i];
            int nextX = x + deltaX[i];

            if (nextY < 0 || nextX < 0)
                continue;
            if (nextY >= N || nextX >= M)
                continue;

            if (adj[nextY][nextX] == 0)
                adj_temp[y][x]--;
        }

        if (adj_temp[y][x] > 0)
            q_temp.push({y, x});
        else
            adj_temp[y][x] = 0;
    }
}

//count
void BFS(int _y, int _x) {
    queue<pair<int, int>> _q;
    _q.push({_y, _x});

    while (!_q.empty()) {
        int y = _q.front().first;
        int x = _q.front().second;

        _q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = y + deltaY[i];
            int nextX = x + deltaX[i];

            if (nextY < 0 || nextX < 0)
                continue;
            if (nextY >= N || nextX >= M)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (adj[nextY][nextX] == 0)
                continue;

            visited[nextY][nextX] = true;
            _q.push({nextY, nextX});
        }
    }
}

int main() {
    cin >> N >> M;

    adj = vector<vector<int>>(N, vector<int>(M));
    adj_temp = vector<vector<int>>(N, vector<int>(M));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> adj[y][x];

            adj_temp[y][x] = adj[y][x];

            if (adj[y][x] > 0)
                q.push({y, x});
        }
    }

    int year = 0;
    while (!q.empty()) {
        year++;
        BFS();
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                adj[y][x] = adj_temp[y][x];
            }
        }

        visited = vector<vector<bool>>(N, vector<bool>(M));

        int cnt = 0;
        while (!q_temp.empty()) {
            int y = q_temp.front().first;
            int x = q_temp.front().second;
            q.push({y, x});

            if (!visited[y][x]) {
                BFS(y, x);
                cnt++;
            }

            if (cnt > 1) {
                cout << year << endl;
                return 0;
            }

            q_temp.pop();
        }
    }

    cout << 0 << endl;
    return 0;
}
