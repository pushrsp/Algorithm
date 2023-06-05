#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T, DP[101][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    vector<pair<int, int>> vec(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> vec[i].first >> vec[i].second;

    for (int n = 1; n <= N; ++n) {
        int study_time = vec[n].first, score = vec[n].second;

        for (int t = 0; t <= T; ++t) {
            if (study_time <= t)
                DP[n][t] = max(DP[n - 1][t], DP[n - 1][t - study_time] + score);
            else
                DP[n][t] = DP[n - 1][t];
        }
    }

    cout << DP[N][T] << '\n';
    return 0;
}