#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

struct Point {
    int y, x, dist;
    bool staff;
};

int N, M, HX, HY, EX, EY, Map[1001][1001];
int DY[4] = {-1, 0, 1, 0};
int DX[4] = {0, -1, 0, 1};
bool Visited[1001][1001][2];

bool in_range(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

void bfs() {
    queue<Point> q;

    Visited[HY][HX][0] = true;
    q.push({HY, HX, 0, false});

    int ret = INT32_MAX;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.y == EY && curr.x == EX) {
            ret = min(ret, curr.dist);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nextY = curr.y + DY[i];
            int nextX = curr.x + DX[i];

            if (!in_range(nextY, nextX))
                continue;
            if (curr.staff) {
                if (Map[nextY][nextX] == 0 && !Visited[nextY][nextX][curr.staff]) {
                    Visited[nextY][nextX][curr.staff] = true;
                    q.push({nextY, nextX, curr.dist + 1, curr.staff});
                }
            } else {
                if (Map[nextY][nextX] == 0) {
                    if (!Visited[nextY][nextX][0]) {
                        Visited[nextY][nextX][0] = true;
                        q.push({nextY, nextX, curr.dist + 1, false});
                    }
                } else {
                    if (!Visited[nextY][nextX][1]) {
                        Visited[nextY][nextX][1] = true;
                        q.push({nextY, nextX, curr.dist + 1, true});
                    }
                }
            }
        }
    }

    if (ret == INT32_MAX)
        cout << -1 << '\n';
    else
        cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    cin >> HY >> HX;
    cin >> EY >> EX;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x)
            cin >> Map[y][x];
    }

    bfs();

    return 0;
}