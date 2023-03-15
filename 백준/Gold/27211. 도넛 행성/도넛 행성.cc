#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 1001

using namespace std;

int N, M, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
vector<vector<int>> Map;
bool Visited[MAX][MAX];

void bfs(int nowY, int nowX) {
    queue<pair<int, int>> q;

    Visited[nowY][nowX] = true;
    q.emplace(nowY, nowX);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = curr.first + DY[i], nextX = curr.second + DX[i];

            if (nextY >= N)
                nextY = 0;
            if (nextY < 0)
                nextY = N - 1;
            if (nextX >= M)
                nextX = 0;
            if (nextX < 0)
                nextX = M - 1;

            if (Map[nextY][nextX])
                continue;
            if (Visited[nextY][nextX])
                continue;

            Visited[nextY][nextX] = true;
            q.emplace(nextY, nextX);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Map = vector<vector<int>>(N, vector<int>(M));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x)
            cin >> Map[y][x];
    }

    int ret = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (Map[y][x] == 0 && !Visited[y][x]) {
                bfs(y, x);
                ret += 1;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}