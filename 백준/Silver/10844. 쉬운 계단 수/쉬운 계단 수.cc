#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

const ll MOD = 1000000000;
ll N, DP[101][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= 9; ++i)
        DP[1][i] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0)
                DP[i][j] = DP[i - 1][1];
            else if (j == 9)
                DP[i][j] = DP[i - 1][8];
            else
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];

            DP[i][j] %= MOD;
        }
    }

    ll answer = 0;
    for (int i = 0; i < 10; ++i)
        answer += DP[N][i];

    cout << answer % MOD << '\n';
    
    return 0;
}