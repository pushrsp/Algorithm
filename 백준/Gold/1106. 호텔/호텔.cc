#include <iostream>
#include <vector>
#include <cstring>

#define INF 987654321

using namespace std;

int C, N, DP[21][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> C >> N;

    vector<pair<int, int>> vec(N + 1);
    for (int n = 1; n <= N; ++n)
        cin >> vec[n].first >> vec[n].second;

    for (auto &dp: DP)
        fill(dp, dp + 1001, INF);

    for (int n = 1; n <= N; ++n) {
        int cost = vec[n].first, customer = vec[n].second;

        for (int c = 1; c <= C; ++c) {
            int d = c / customer, r = c % customer;
            if (r > 0)
                d += 1;

            DP[n][c] = min(DP[n - 1][c], cost * d);
            if (customer <= c)
                DP[n][c] = min(DP[n][c], min(DP[n - 1][c - customer] + cost, DP[n][c - customer] + cost));
        }
    }

    cout << DP[N][C] << '\n';

    return 0;
}