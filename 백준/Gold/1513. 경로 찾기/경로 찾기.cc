#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000007;

int N, M, C, DP[51][51][51][51];
vector<vector<int>> Map;

int go(int nowY, int nowX, int count, int visited) {
    if (count < 0)
        return 0;
    if (nowY > N)
        return 0;
    if (nowX > M)
        return 0;
    if (nowY == N && nowX == M) {
        if (count == 0 && Map[N][M] == 0)
            return 1;
        if (count == 1 && Map[N][M] > visited)
            return 1;

        return 0;
    }

    int &ret = DP[nowY][nowX][count][visited];
    if (ret != -1)
        return ret;

    ret = 0;
    if (Map[nowY][nowX] == 0)
        ret = (go(nowY + 1, nowX, count, visited) + go(nowY, nowX + 1, count, visited)) % MOD;
    else if (Map[nowY][nowX] > visited)
        ret = (go(nowY + 1, nowX, count - 1, Map[nowY][nowX]) +
               go(nowY, nowX + 1, count - 1, Map[nowY][nowX])) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;

    memset(DP, -1, sizeof(DP));
    Map = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    for (int c = 1; c <= C; ++c) {
        int y, x;
        cin >> y >> x;

        Map[y][x] = c;
    }

    for (int c = 0; c <= C; ++c)
        cout << go(1, 1, c, 0) << ' ';

    return 0;
}