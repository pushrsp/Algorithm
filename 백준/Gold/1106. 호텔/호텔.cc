#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define INF 987654321

using namespace std;

int C, N, DP[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> C >> N;

    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; ++i)
        cin >> vec[i].first >> vec[i].second;

    for (int i = 1; i <= 100000; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i % vec[j].first == 0)
                DP[i] = max(DP[i], (i / vec[j].first) * vec[j].second);

            if (i - vec[j].first > 0)
                DP[i] = max(DP[i], DP[i - vec[j].first] + vec[j].second);
        }

        if (DP[i] >= C) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}