#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int N, M, T, K;

bool in_range(int a, int val, int b) {
    return a <= val and val <= b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> T >> K;

    vector<pair<int, int>> points(T);
    vector<int> xy[2];
    for (int t = 0; t < T; ++t) {
        cin >> points[t].first >> points[t].second;

        xy[0].push_back(points[t].first);
        xy[1].push_back(points[t].second);
    }

    xy[0].push_back(N - K);
    xy[1].push_back(M - K);

    for (int i = 0; i < 2; ++i) {
        sort(xy[i].begin(), xy[i].end());
        xy[i].erase(unique(xy[i].begin(), xy[i].end()), xy[i].end());
    }

    int retX = 0, retY = 0, retCnt = 0;
    for (int cur_x: xy[0]) {
        for (int cur_y: xy[1]) {
            if (cur_x + K > N || cur_y + K > M)
                continue;

            int cnt = 0;
            for (int t = 0; t < T; ++t) {
                if (in_range(cur_x, points[t].first, cur_x + K) && in_range(cur_y, points[t].second, cur_y + K))
                    cnt += 1;
            }

            if (cnt > retCnt) {
                retCnt = cnt;
                retX = cur_x;
                retY = cur_y;
            }
        }
    }

    cout << retX << ' ' << retY + K << '\n';
    cout << retCnt << '\n';

    return 0;
}