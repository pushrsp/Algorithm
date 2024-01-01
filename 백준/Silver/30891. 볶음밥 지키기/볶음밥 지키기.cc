#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct Point {
    int count, x, y;
};

int N, R;

bool desc(const Point &a, const Point &b) {
    return a.count > b.count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> R;

    R *= R;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n) {
        cin >> vec[n].first >> vec[n].second;
        vec[n].first += 100, vec[n].second += 100;
    }

    vector<pair<int, int>> xy;
    for (int x = 0; x <= 200; ++x) {
        for (int y = 0; y <= 200; ++y) {
            xy.emplace_back(x, y);
        }
    }

    vector<Point> ret;
    for (int i = 0; i < xy.size(); ++i) {
        int px = xy[i].first, py = xy[i].second, count = 0;

        for (int j = 0; j < N; ++j) {
            int a = abs(px - vec[j].first);
            a *= a;

            int b = abs(py - vec[j].second);
            b *= b;

            if (a + b <= R)
                count += 1;
        }

        ret.push_back({count, px, py});
    }

    sort(ret.begin(), ret.end(), desc);

    cout << ret[0].x - 100 << ' ' << ret[0].y - 100 << '\n';

    return 0;
}