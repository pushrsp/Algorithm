#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

const int MOD = 1000000000;
int N, K, DP[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int k = 0; k <= K; ++k)
        DP[1][k] = k;

    for (int n = 2; n <= N; ++n) {
        for (int k = 1; k <= K; ++k)
            DP[n][k] = (DP[n - 1][k] + DP[n][k - 1]) % MOD;
    }

    cout << DP[N][K] << '\n';

    return 0;
}