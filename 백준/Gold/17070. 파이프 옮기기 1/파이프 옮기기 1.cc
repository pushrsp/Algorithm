#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 17

using namespace std;

int N, DP[MAX][MAX][3];
vector<vector<int>> Map;

bool InRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int go(int y, int x, int type) {
    if (!InRange(y, x))
        return 0;
    if (Map[y][x])
        return 0;
    if (type == 2) {
        if (Map[y - 1][x])
            return 0;
        if (Map[y][x - 1])
            return 0;
    }

    if (y == N - 1 && x == N - 1)
        return 1;

    int &ret = DP[y][x][type];
    if (ret != -1)
        return ret;

    ret = 0;
    if (type == 0) {
        ret += go(y, x + 1, 0);
        ret += go(y + 1, x + 1, 2);
    } else if (type == 1) {
        ret += go(y + 1, x, 1);
        ret += go(y + 1, x + 1, 2);
    } else {
        ret += go(y, x + 1, 0);
        ret += go(y + 1, x, 1);
        ret += go(y + 1, x + 1, 2);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    Map = vector<vector<int>>(N, vector<int>(N));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x)
            cin >> Map[y][x];
    }

    ::memset(DP, -1, sizeof(DP));

    cout << go(0, 1, 0) << '\n';
    return 0;
}