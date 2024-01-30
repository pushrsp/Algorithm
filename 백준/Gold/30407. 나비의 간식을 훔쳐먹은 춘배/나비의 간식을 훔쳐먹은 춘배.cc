#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

#define ll long long

using namespace std;

int N, H, D, K, A[25], DP[26][4002][2];

int go(int n, int d, bool ulti) {
    if (n >= N)
        return 0;

    int &ret = DP[n][d][ulti];
    if (ret != -1)
        return ret;

    ret = 987654321;

    int offset = (A[n] - d) / 2;
    ret = min(ret, go(n + 1, d, ulti) + (offset <= 0 ? 0 : offset));

    offset = A[n] - (d + K);
    ret = min(ret, go(n + 1, d + K, ulti) + (offset <= 0 ? 0 : offset));

    if (!ulti) {
        offset = A[n] - d;
        ret = min(ret, go(n + 2, d + K, true) + (offset <= 0 ? 0 : offset));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> H >> D >> K;

    for (int n = 0; n < N; ++n)
        cin >> A[n];

    ::memset(DP, -1, sizeof(DP));

    int ret = H - go(0, D, false);

    if (ret > 0)
        cout << ret << '\n';
    else
        cout << -1 << '\n';

    return 0;
}