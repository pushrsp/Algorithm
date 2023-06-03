#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, M, Arr[21], DP[10001][21];

int go(int n, int sum) {
    if (sum > M)
        return 0;
    if (sum == M)
        return 1;
    if (n > N)
        return 0;

    int &ret = DP[sum][n];
    if (ret != -1)
        return ret;

    ret = 0;
    ret += go(n, sum + Arr[n]);
    ret += go(n + 1, sum);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        ::memset(DP, -1, sizeof(DP));

        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> Arr[i];

        cin >> M;
        cout << go(1, 0) << '\n';
    }
    return 0;
}