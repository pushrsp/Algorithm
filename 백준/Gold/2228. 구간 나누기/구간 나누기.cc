#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 987654321

using namespace std;

int N, M, T[101], A[108], Sum[101][101], DP[101][101];

int go(int n, int m) {
    if (m == M + 1)
        return 0;
    if (n > N)
        return -INF;

    int &ret = DP[n][m];
    if (ret != -1)
        return ret;

    ret = go(n + 1, m);
    for (int i = n; i <= N; ++i)
        ret = max(ret, Sum[n][i] + go(i + 2, m + 1));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    ::memset(DP, -1, sizeof(DP));

    for (int n = 1; n <= N; ++n) {
        int sum = 0;
        for (int i = n; i <= N; ++i) {
            sum += A[i];
            Sum[n][i] = sum;
        }
    }

    cout << go(1, 1) << '\n';

    return 0;
}