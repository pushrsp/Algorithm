#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

#define MAX 501
#define ll long long

using namespace std;

int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
int N, M, Map[MAX][MAX];
ll DP[MAX][MAX][4];

bool InRange(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

ll go(int curY, int curX, int dir) {
    if (curY == N && curX == M)
        return 1;

    ll &ret = DP[curY][curX][dir];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 4; ++i) {
        int nextY = curY + DY[i], nextX = curX + DX[i];

        if (!InRange(nextY, nextX))
            continue;
        if (Map[curY][curX] <= Map[nextY][nextX])
            continue;

        ret += go(nextY, nextX, i);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ::memset(DP, -1, sizeof(DP));

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> Map[i][j];
        }
    }

    cout << go(1, 1, 0) << '\n';
    return 0;
}