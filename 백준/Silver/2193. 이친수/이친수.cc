#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define ll long long

using namespace std;

ll N, DP[91][2];

ll go(ll n, int prev) {
    if (n == 1)
        return 1;

    ll &ret = DP[n][prev];
    if (ret)
        return ret;

    if (prev)
        ret = go(n - 1, 0);
    else
        ret = go(n - 1, 0) + go(n - 1, 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cout << go(N, 1) << '\n';
    return 0;
}
