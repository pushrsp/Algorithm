#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

const int MOD = 1000000000;
int N, K;
ll DP[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int n = 0; n <= N; ++n)
        DP[1][n] = 1;

    for (int k = 2; k <= K; ++k) {
        for (int n = 0; n <= N; ++n) {
            for (int i = 0; i <= n; ++i)
                DP[k][n] += DP[k - 1][i];

            DP[k][n] %= MOD;
        }
    }

    cout << DP[K][N] << '\n';

    return 0;
}