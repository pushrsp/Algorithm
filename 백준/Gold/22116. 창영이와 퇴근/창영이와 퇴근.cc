#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define INF 987654321

using namespace std;

int N;
int DY[4] = {-1, 0, 1, 0};
int DX[4] = {0, -1, 0, 1};
ll M[1001][1001];
bool Visited[1001][1001];

bool in_range(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= N;
}

bool bfs(ll a) {
    queue<pair<int, int>> q;

    memset(Visited, false, sizeof(Visited));
    q.emplace(1, 1);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.first == N && curr.second == N)
            return true;

        for (int i = 0; i < 4; ++i) {
            int nextY = curr.first + DY[i];
            int nextX = curr.second + DX[i];

            if (!in_range(nextY, nextX))
                continue;
            if (Visited[nextY][nextX])
                continue;
            if (abs(M[nextY][nextX] - M[curr.first][curr.second]) > a)
                continue;

            Visited[nextY][nextX] = true;
            q.emplace(nextY, nextX);
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x)
            cin >> M[y][x];
    }

    ll ret = INT64_MAX;
    ll left = 0, right = 2000000000, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (bfs(mid)) {
            right = mid - 1;
            ret = min(ret, mid);
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}