#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000007;
int N, M, C, DP[51][51][51][51];
vector<vector<int>> Map;

int go(int nowY, int nowX, int cnt, int prev) {
    if (nowY > N || nowX > M)
        return 0;
    if (nowY == N && nowX == M) {
        if (cnt == 0 && Map[nowY][nowX] == 0)
            return 1;
        if (cnt == 1 && Map[nowY][nowX] > prev)
            return 1;

        return 0;
    }

    int &ret = DP[nowY][nowX][cnt][prev];
    if (ret != -1)
        return ret;

    ret = 0;
    if (Map[nowY][nowX] == 0)
        ret = (go(nowY + 1, nowX, cnt, prev) + go(nowY, nowX + 1, cnt, prev)) % MOD;
    else if (Map[nowY][nowX] > prev)
        ret = (go(nowY + 1, nowX, cnt - 1, Map[nowY][nowX]) + go(nowY, nowX + 1, cnt - 1, Map[nowY][nowX])) % MOD;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;

    memset(DP, -1, sizeof(DP));
    Map = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= C; ++i) {
        int y, x;
        cin >> y >> x;
        Map[y][x] = i;
    }

    for (int i = 0; i <= C; ++i)
        cout << go(1, 1, i, 0) << ' ';

    return 0;
}