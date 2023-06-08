#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, DP[101][301][301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    vector<pair<int, int>> vec(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> vec[i].first >> vec[i].second;

    for (int n = 1; n <= N; ++n) {
        int h = vec[n].first, p = vec[n].second;

        for (int m = 1; m <= M; ++m) {
            for (int k = 1; k <= K; ++k) {
                if (h <= m && p <= k)
                    DP[n][m][k] = max(DP[n - 1][m][k], DP[n - 1][m - h][k - p] + 1);
                else
                    DP[n][m][k] = DP[n - 1][m][k];
            }
        }
    }

    cout << DP[N][M][K] << '\n';

    return 0;
}