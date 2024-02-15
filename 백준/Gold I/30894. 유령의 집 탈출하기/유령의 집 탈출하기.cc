#include <iostream>
#include <queue>

#define INF 987654321

using namespace std;

struct G {
    int d, y, x;
};

int N, M, SY, SX, DY, DX;
int Y[4] = {0, 1, 0, -1}, X[4] = {1, 0, -1, 0};
vector<G> Ghost;
vector<string> Map;
bool Visited[201][201][4];

/*
 * 0: 오른쪽
 * 1: 아래
 * 2: 왼쪽
 * 3: 위
 */

bool in_range(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int bfs() {
    queue<vector<int>> q;

    q.push({0, SY, SX});
    Visited[SY][SX][0] = true;

    int ret = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int curC = curr[0], curY = curr[1], curX = curr[2];
        if (curY == DY && curX == DX) {
            ret = curC;
            break;
        }

        if (!Visited[curY][curX][(curC + 1) % 4])
            q.push({curC + 1, curY, curX});

        int nextY, nextX;
        for (int i = 0; i < 4; ++i) {
            nextY = curY + Y[i], nextX = curX + X[i];

            if (!in_range(nextY, nextX))
                continue;

            if (Map[nextY][nextX] == '.' && !Visited[nextY][nextX][(curC + 1) % 4]) {
                Visited[nextY][nextX][(curC + 1) % 4] = true;
                q.push({curC + 1, nextY, nextX});
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Map = vector<string>(N);

    cin >> SY >> SX >> DY >> DX;

    SY--, SX--;
    DY--, DX--;

    for (int y = 0; y < N; ++y) {
        cin >> Map[y];

        for (int x = 0; x < M; ++x) {
            if ('0' <= Map[y][x] && Map[y][x] <= '3')
                Ghost.push_back({Map[y][x] - '0', y, x});
        }
    }

    for (auto &g: Ghost) {
        for (int i = 0; i < 4; ++i) {
            int dir = (g.d + i) % 4;
            int curY = g.y, curX = g.x;
            while (true) {
                curY += Y[dir], curX += X[dir];

                if (!in_range(curY, curX))
                    break;
                if (Map[curY][curX] != '.')
                    break;

                Visited[curY][curX][i] = true;
            }
        }
    }

    int ret = bfs();
    if (ret != 0)
        cout << ret << '\n';
    else
        cout << "GG" << '\n';

    return 0;
}