#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int y, x, k, d;
};

int W, H, K;
int DY1[4] = {-1, 0, 1, 0}, DX1[4] = {0, -1, 0, 1};
int DY2[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int DX2[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int Board[201][201];
bool Visited[201][201][31];

bool in_range(int y, int x) {
    return 1 <= y && y <= H && 1 <= x && x <= W;
}

int bfs() {
    queue<Point> q;
    q.push({1, 1, K, 0});

    int ret = INT32_MAX;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.y == H && curr.x == W) {
            ret = min(ret, curr.d);
            continue;
        }

        if (!in_range(curr.y, curr.x))
            continue;
        if (Board[curr.y][curr.x])
            continue;
        if (Visited[curr.y][curr.x][curr.k])
            continue;

        Visited[curr.y][curr.x][curr.k] = true;
        for (int i = 0; i < 4; ++i) {
            int nextY = curr.y + DY1[i], nextX = curr.x + DX1[i];
            q.push({nextY, nextX, curr.k, curr.d + 1});
        }

        if (curr.k - 1 < 0)
            continue;

        for (int i = 0; i < 8; ++i) {
            int nextY = curr.y + DY2[i], nextX = curr.x + DX2[i];
            q.push({nextY, nextX, curr.k - 1, curr.d + 1});
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K;
    cin >> W >> H;

    for (int y = 1; y <= H; ++y) {
        for (int x = 1; x <= W; ++x)
            cin >> Board[y][x];
    }

    int ret = bfs();
    if (ret == INT32_MAX)
        cout << -1 << '\n';
    else
        cout << ret << '\n';

    return 0;
}