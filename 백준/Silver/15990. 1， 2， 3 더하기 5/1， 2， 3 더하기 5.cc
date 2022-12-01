#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

const ll MOD = 1000000009;
ll T, N, DP[4][100001];

ll go(ll n, ll prev) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    ll &ret = DP[prev][n];
    if (ret)
        return ret;

    if (prev == 1)
        return ret = ((go(n - 2, 2) % MOD) + (go(n - 3, 3) % MOD)) % MOD;
    else if (prev == 2)
        return ret = ((go(n - 1, 1) % MOD) + (go(n - 3, 3) % MOD)) % MOD;
    else
        return ret = ((go(n - 1, 1) % MOD) + (go(n - 2, 2) % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        ll answer = 0;
        for (ll i = 1; i <= 3; ++i)
            answer += go(N - i, i);

        cout << answer % MOD << '\n';
    }
    return 0;
}