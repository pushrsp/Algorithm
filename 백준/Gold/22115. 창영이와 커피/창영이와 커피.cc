#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define INF 987654321

using namespace std;

struct P {
    int n, k, count;
};

int N, K, C[101], DP[101][100001];

int go(int n, int k) {
    if (k > K)
        return INF;
    if (n > N) {
        if (k != K)
            return INF;

        return 0;
    }

    int &ret = DP[n][k];
    if (ret != -1)
        return ret;

    ret = INF;
    ret = min(ret, go(n + 1, k + C[n]) + 1);
    ret = min(ret, go(n + 1, k));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int n = 1; n <= N; ++n)
        cin >> C[n];

    memset(DP, -1, sizeof(DP));

    int ret = go(0, 0);
    if (ret >= INF)
        cout << -1 << '\n';
    else
        cout << ret << '\n';

    return 0;
}