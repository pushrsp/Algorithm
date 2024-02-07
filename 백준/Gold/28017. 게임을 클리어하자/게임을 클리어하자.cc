#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, M, A[501][501], DP[501][501];

int go(int n, int prev) {
    if (n > N)
        return 0;

    int &ret = DP[n][prev];
    if (ret != -1)
        return ret;

    ret = 987654321;
    for (int m = 1; m <= M; ++m) {
        if (prev == m)
            continue;

        ret = min(ret, go(n + 1, m) + A[n][m]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m)
            cin >> A[n][m];
    }

    ::memset(DP, -1, sizeof(DP));

    cout << go(1, 0) << '\n';

    return 0;
}