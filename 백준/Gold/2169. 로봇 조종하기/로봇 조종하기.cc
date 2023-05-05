#include <iostream>
#include <queue>
#include <map>
#include <vector>

#define MAX 1001
#define ll long long

using namespace std;

int N, M, DY[3] = {0, 1, 0}, DX[3] = {-1, 0, 1};
int Map[MAX][MAX], DP[MAX][MAX][3];
bool Visited[MAX][MAX];

bool InRange(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

int go(int nowY, int nowX, int dir) {
    if (nowY == N && nowX == M)
        return Map[N][M];

    int &ret = DP[nowY][nowX][dir];
    if (ret != -987654321)
        return ret;

    Visited[nowY][nowX] = true;

    for (int i = 0; i < 3; ++i) {
        int nextY = nowY + DY[i], nextX = nowX + DX[i];

        if (!InRange(nextY, nextX))
            continue;
        if (Visited[nextY][nextX])
            continue;

        ret = max(ret, go(nextY, nextX, i) + Map[nowY][nowX]);
    }

    Visited[nowY][nowX] = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            cin >> Map[y][x];
        }
    }

    DP[0][0][0] = -987654321;
    DP[0][0][1] = -987654321;
    DP[0][0][2] = -987654321;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            DP[i][j][0] = -987654321;
            DP[i][j][1] = -987654321;
            DP[i][j][2] = -987654321;
        }
    }

    cout << go(1, 1, 0) << '\n';

    return 0;
}