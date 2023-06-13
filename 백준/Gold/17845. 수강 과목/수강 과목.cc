#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K, DP[1001][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    vector<pair<int, int>> vec(K + 1);
    for (int i = 1; i <= K; ++i)
        cin >> vec[i].first >> vec[i].second;

    for (int k = 1; k <= K; ++k) {
        int i = vec[k].first, t = vec[k].second;

        for (int n = 1; n <= N; ++n) {
            if (t <= n)
                DP[k][n] = max(DP[k - 1][n], DP[k - 1][n - t] + i);
            else
                DP[k][n] = max(DP[k - 1][n], DP[k][n - 1]);
        }
    }

    cout << DP[K][N] << '\n';

    return 0;
}