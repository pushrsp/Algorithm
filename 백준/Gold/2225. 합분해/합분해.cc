#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

const int MOD = 1000000000;
int N, K, DP[201][201];

int go(int n, int k) {
    if (n < 0)
        return 0;
    if (k == K) {
        if (n == 0)
            return 1;

        return 0;
    }

    int &ret = DP[n][k];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i <= N; ++i) {
        ret += go(n - i, k + 1);
        ret %= MOD;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    ::memset(DP, -1, sizeof(DP));

    cout << go(N, 0) << '\n';

    return 0;
}