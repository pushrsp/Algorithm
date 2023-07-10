#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, T, DP[101][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    vector<pair<int, int>> vec(N + 1);
    for (int n = 1; n <= N; ++n)
        cin >> vec[n].first >> vec[n].second;

    for (int n = 1; n <= N; ++n) {
        int time = vec[n].first, score = vec[n].second;

        for (int t = 1; t <= T; ++t) {
            if (time <= t) {
                DP[n][t] = max(DP[n - 1][t - time] + score, DP[n - 1][t]);
            } else {
                DP[n][t] = DP[n - 1][t];
            }
        }
    }

    cout << DP[N][T] << '\n';

    return 0;
}