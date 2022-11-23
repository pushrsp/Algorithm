#include <iostream>
#include <vector>

using namespace std;

int N, K, Dp[101][100001];
vector<vector<int>> Vec;

int go(int idx, int _time) {
    if (idx == N)
        return 0;

    int &ret = Dp[idx][_time];
    if (ret)
        return ret;

    ret = INT32_MIN;
    if (_time - Vec[idx][0] >= 0)
        ret = max(ret, go(idx + 1, _time - Vec[idx][0]) + Vec[idx][1]);
    if (_time - Vec[idx][2] >= 0)
        ret = max(ret, go(idx + 1, _time - Vec[idx][2]) + Vec[idx][3]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    Vec = vector<vector<int>>(N, vector<int>(4));

    for (int n = 0; n < N; ++n)
        cin >> Vec[n][0] >> Vec[n][1] >> Vec[n][2] >> Vec[n][3];

    cout << go(0, K) << '\n';
    return 0;
}