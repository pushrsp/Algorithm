#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = -200000102;
int N, A[200005], Sum[200005], DP[200005][2];

int go(int n, int pressed) {
    if (n > N)
        return 0;

    int &ret = DP[n][pressed];
    if (ret != INF)
        return ret;

    ret = max(ret, go(n + 3, 1) + ((Sum[min(N, n + 2)] - Sum[n - 1]) * 2));
    ret = max(ret, go(n + 1, 0) + A[n]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n) {
        cin >> A[n];

        DP[n][0] = INF;
        DP[n][1] = INF;
        Sum[n] = Sum[n - 1] + A[n];
    }

    for (int n = N + 1; n <= N + 3; ++n)
        Sum[n] = Sum[N];

    cout << go(1, 0) << '\n';

    return 0;
}