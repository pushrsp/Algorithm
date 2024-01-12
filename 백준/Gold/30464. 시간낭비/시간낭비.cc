#include <iostream>
#include <vector>
#include <set>
#include <cstring>

#define INF -987654321

using namespace std;

int N, A[200001], DP[200001][3][2];

/*
 * d 0: ->
 * d 1: <-
 */
int go(int n, int c, int d) {
    if (n < 1 || n > N)
        return INF;

    if (n == N)
        return 0;

    int &ret = DP[n][c][d];
    if (ret != -1)
        return ret;

    ret = INF;

    int nextN = A[n] * (d ? -1 : 1);
    ret = max(ret, go(n + nextN, c, d) + 1);

    if (c > 0)
        ret = max(ret, go(n - nextN, c - 1, (d + 1) % 2) + 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    fill(&DP[0][0][0], &DP[0][0][0] + 200001 * 3 * 2, -1);

    int ret = go(1, 2, 0);

    if (ret > 0)
        cout << ret << '\n';
    else
        cout << -1 << '\n';

    return 0;
}