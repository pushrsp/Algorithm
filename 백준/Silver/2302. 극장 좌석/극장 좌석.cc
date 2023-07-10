#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, Arr[41], DP[41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;

    vector<int> vip(M);
    for (int m = 0; m < M; ++m)
        cin >> vip[m];

    DP[0] = 1, DP[1] = 1, DP[2] = 2;
    for (int i = 3; i <= N; ++i)
        DP[i] = DP[i - 1] + DP[i - 2];

    int ret = 1, start = 0;
    for (auto &v: vip) {
        ret *= DP[v - 1 - start];
        start = v;
    }

    ret *= DP[N - start];

    cout << ret << '\n';

    return 0;
}