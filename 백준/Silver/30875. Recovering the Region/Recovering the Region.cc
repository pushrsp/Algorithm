#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int N, Map[51][51];
int DY[4] = {-1, 0, 1, 0};
int DX[4] = {0, -1, 0, 1};
bool Visited[51][51];

bool in_range(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= N;
}

void bfs(int startY, int startX, vector<vector<int>> &ret) {
    queue<pair<int, int>> q;

    Visited[startY][startX] = true;
    q.emplace(startY, startX);

    vector<pair<int, int>> point;
    point.emplace_back(startY, startX);

    set<int> visited;
    visited.insert(Map[startY][startX]);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 3; i <= 3; ++i) {
            int nextY = curr.first + DY[i], nextX = curr.second + DX[i];

            if (!in_range(nextY, nextX))
                continue;
            if (Visited[nextY][nextX])
                continue;
            if (visited.find(Map[nextY][nextX]) != visited.end())
                continue;

            visited.insert(Map[nextY][nextX]);
            q.emplace(nextY, nextX);
            Visited[nextY][nextX] = true;
            point.emplace_back(nextY, nextX);
        }
    }

    for (auto &p: point)
        ret[p.first][p.second] = INT32_MAX;

    visited.clear();

    for (auto &p: point) {
        for (int i = 0; i < 4; ++i) {
            int nextY = p.first + DY[i], nextX = p.second + DX[i];

            if (!in_range(nextY, nextX))
                continue;

            visited.insert(ret[nextY][nextX]);
        }
    }

    for (int n = 1; n <= N; ++n) {
        if (visited.find(n) == visited.end()) {
            for (auto &p: point)
                ret[p.first][p.second] = n;

            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x)
            cin >> Map[y][x];
    }

    vector<vector<int>> ret(N + 1, vector<int>(N + 1, 0));
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            if (Visited[y][x])
                continue;

            bfs(y, x, ret);
        }
    }

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cout << ret[y][x] << ' ';
        }

        cout << '\n';
    }

    return 0;
}