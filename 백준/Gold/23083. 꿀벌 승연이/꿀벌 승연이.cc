#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define MAX 1001

using namespace std;

const ll MOD = 1e9 + 7;
ll DP[MAX][MAX];
int N, M, K, DestY, DestX;
vector<vector<bool>> Map;

int DY[2][3] = {
        {1, 0,  1},
        {1, -1, 0},
};
int DX[2][3] = {
        {0, 1, 1},
        {0, 1, 1}
};

bool InRange(int y, int x) {
    return 0 <= y && y <= N + 1 && 0 <= x && x <= M;
}

ll go(int nowY, int nowX) {
    if (!InRange(nowY, nowX))
        return 0;
    if (!Map[nowY][nowX])
        return 0;
    if (nowY == DestY && nowX == DestX)
        return 1;

    ll &ret = DP[nowY][nowX];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 3; ++i) {
        int nextY = nowY + DY[nowX % 2][i], nextX = nowX + DX[nowX % 2][i];
        ret += go(nextY, nextX);
        ret %= MOD;
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Map = vector<vector<bool>>(N + 1, vector<bool>(M, false));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            Map[y + x % 2][x] = true;
        }
    }

    for (int i = 0; i < MAX; ++i)
        fill(DP[i], DP[i] + MAX, -1);

    cin >> K;

    int yy, xx;
    for (int i = 0; i < K; ++i) {
        cin >> yy >> xx;
        yy--, xx--;
        Map[yy + xx % 2][xx] = false;
    }

    N--, M--;
    DestY = N + M % 2, DestX = M;

    cout << go(0, 0) << '\n';

    return 0;
}