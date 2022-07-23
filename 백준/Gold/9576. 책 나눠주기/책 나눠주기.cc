#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int T;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;

        vector<pair<int, int>> p(M);
        vector<bool> books(N + 1, false);

        for (int m = 0; m < M; ++m) {
            cin >> p[m].first >> p[m].second;
        }

        sort(p.begin(), p.end(), cmp_pair);

        int cnt = 0;
        for (auto &pp: p) {
            for (int i = pp.first; i <= pp.second; ++i) {
                if (!books[i]) {
                    books[i] = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}