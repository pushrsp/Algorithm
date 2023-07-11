#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K, DP[101][301][301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    vector<pair<int, int>> vec(N + 1);
    for (int n = 1; n <= N; ++n)
        cin >> vec[n].first >> vec[n].second;

    for (int n = 1; n <= N; ++n) {
        int cheese = vec[n].first, potato = vec[n].second;

        for (int m = 1; m <= M; ++m) {
            for (int k = 1; k <= K; ++k) {
                if (cheese <= m && potato <= k) {
                    DP[n][m][k] = max(DP[n - 1][m][k], DP[n - 1][m - cheese][k - potato] + 1);
                } else {
                    DP[n][m][k] = DP[n - 1][m][k];
                }
            }
        }
    }

    cout << DP[N][M][K] << '\n';

    return 0;
}