#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> WEIGHT, VALUE;
vector<vector<int>> dp;

int main() {
    cin >> N >> K;

    WEIGHT = vector<int>(N + 1, 0);
    VALUE = vector<int>(N + 1, 0);
    dp = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
    for (int n = 1; n <= N; ++n)
        cin >> WEIGHT[n] >> VALUE[n];

    for (int k = 1; k <= K; ++k) {
        for (int w = 1; w <= N; ++w) {
            if (WEIGHT[w] <= k)
                dp[w][k] = max(dp[w - 1][k], dp[w - 1][k - WEIGHT[w]] + VALUE[w]);
            else
                dp[w][k] = dp[w - 1][k];
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}