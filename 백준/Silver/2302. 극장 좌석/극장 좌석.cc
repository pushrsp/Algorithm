#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, DP[41], VIP[41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;
    for (int m = 0; m < M; ++m)
        cin >> VIP[m];

    DP[0] = 1, DP[1] = 1, DP[2] = 2;
    for (int n = 3; n <= N; ++n)
        DP[n] = DP[n - 1] + DP[n - 2];

    int ret = 1, prev = 0;
    for (int m = 0; m < M; ++m) {
        ret *= DP[VIP[m] - prev - 1];
        prev = VIP[m];
    }

    ret *= DP[N - prev];
    cout << ret << '\n';
    return 0;
}