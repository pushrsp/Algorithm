#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N, M, T, K;

bool in_range(int p, int t) {
    return p <= t && t <= p + K;
}

int go(int x, int y, vector<pair<int, int>> &v) {
    int ret = 0;
    for (auto &p: v) {
        if (in_range(x, p.first) && in_range(y, p.second))
            ret++;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> T >> K;

    vector<pair<int, int>> v(T);
    for (int t = 0; t < T; ++t)
        cin >> v[t].first >> v[t].second;

    int cnt = 0, x, y;
    for (int i = 0; i < T; ++i) {
        int xx = v[i].first;
        if (v[i].first + K > N)
            xx = N - K;

        for (int j = 0; j < T; ++j) {
            int yy = v[j].second;
            if (v[j].second + K > M)
                yy = M - K;

            int g = go(xx, yy, v);
            if (g > cnt) {
                cnt = g;
                x = xx, y = yy + K;
            }
        }
    }

    cout << x << ' ' << y << '\n';
    cout << cnt << '\n';

    return 0;
}