#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, Arr[200001], DP[200001][2][3];

int go(int n, int m, int o) {
    if (n < 1 || n > N)
        return -1e9;
    if (n == N)
        return 0;

    int &ret = DP[n][m][o];
    if (ret != -1)
        return ret;

    ret = -1e9;

    int dist = Arr[n] * (m ? -1 : 1);

    ret = go(n + dist, m, o) + 1;
    if (o < 2)
        ret = max(ret, go(n - dist, (m + 1) % 2, o + 1) + 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> Arr[n];

    ::memset(DP, -1, sizeof(DP));

    int ret = go(1, 0, 0);
    if (ret > 0)
        cout << ret << '\n';
    else
        cout << -1 << '\n';

    return 0;
}