#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer = INT32_MAX;
vector<vector<int>> map, dist;
vector<pair<int, int>> virus;
vector<bool> virus_visited;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

/*
 * 0: 빈 칸
 * 1: 벽
 * 2: 바이러스
 */

void bfs(int nowY, int nowX) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;

    q.push({nowY, nowX});
    visited[nowY][nowX] = true;
    dist[nowY][nowX] = 0;

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
            if (map[nextY][nextX] == 1)
                continue;
            if (visited[nextY][nextX])
                continue;

            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
            dist[nextY][nextX] = min(dist[now.first][now.second] + 1, dist[nextY][nextX]);
        }
    }
}

void solve() {
    dist = vector<vector<int>>(N, vector<int>(N, INT32_MAX));
    for (int i = 0; i < virus_visited.size(); ++i) {
        if (virus_visited[i])
            bfs(virus[i].first, virus[i].second);
    }

    int a = -1;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (map[y][x] == 0 && dist[y][x] == INT32_MAX)
                return;

            if (map[y][x] == 0 && dist[y][x] != INT32_MAX)
                a = max(a, dist[y][x]);
        }
    }

    answer = min(answer, a);
}

void dfs(int cnt, int idx) {
    if (cnt == M) {
        solve();
        return;
    }

    for (int i = idx; i < virus.size(); ++i) {
        if (virus_visited[i])
            continue;

        virus_visited[i] = true;
        dfs(cnt + 1, i + 1);
        virus_visited[i] = false;
    }
}

int main() {
    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(N, 0));
    int cnt = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];

            if (map[y][x] == 2)
                virus.emplace_back(y, x);

            if (map[y][x] == 0)
                cnt++;
        }
    }

    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    virus_visited = vector<bool>(virus.size(), false);
    dfs(0, 0);

    if (answer == INT32_MAX)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;
}