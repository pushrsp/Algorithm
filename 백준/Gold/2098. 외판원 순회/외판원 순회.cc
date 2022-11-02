#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;
vector<vector<int>> Map, Dp;

int go(int here, int visited) {
    if (visited == (1 << N) - 1)
        return Map[here][0] ? Map[here][0] : INF;

    int &ret = Dp[here][visited];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 0; i < N; ++i) {
        if (visited & (1 << i))
            continue;
        if (Map[here][i] == 0)
            continue;

        ret = min(ret, go(i, visited | 1 << i) + Map[here][i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Map = vector<vector<int>>(N, vector<int>(N, 0));
    Dp = vector<vector<int>>(N, vector<int>(1 << N, -1));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Map[y][x];
        }
    }

    cout << go(0, 1) << '\n';
    return 0;
}