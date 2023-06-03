#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define INF 987654321

using namespace std;

int C, N, DP[21][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> C >> N;

    vector<pair<int, int>> vec(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> vec[i].first >> vec[i].second;

    for (auto &dp: DP)
        fill(dp, dp + 1001, INF);

    for (int n = 1; n <= N; ++n) {
        int price = vec[n].first, quantity = vec[n].second;

        for (int c = 1; c <= C; ++c) {
            int m = c / quantity, r = c % quantity;
            if (r > 0)
                m += 1;

            DP[n][c] = min(m * price, DP[n - 1][c]);
            if (quantity <= c) {
                DP[n][c] = min(DP[n][c], DP[n - 1][c - quantity] + price);
                DP[n][c] = min(DP[n][c], DP[n][c - quantity] + price);
            }
        }
    }

    cout << DP[N][C] << '\n';
    return 0;
}