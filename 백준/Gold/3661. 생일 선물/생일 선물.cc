#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, P, N;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first > b.first;

    return a.second < b.second;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> P >> N;

        vector<pair<int, int>> money(N);
        for (int n = 0; n < N; ++n) {
            cin >> money[n].second;
            money[n].first = n;
        }

        sort(money.begin(), money.end(), cmp_pair);

        vector<pair<int, int>> vec(N);
        for (int n = 0; n < N; ++n) {
            vec[money[n].first].second = min(money[n].second, P / (N - n));
            P -= vec[money[n].first].second;
        }

        if (P > 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int n = 0; n < N; ++n) {
                cout << vec[n].second << " ";
            }

            cout << endl;
        }
    }
    return 0;
}