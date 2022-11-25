#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

int N, M, C, DP[21][1 << 14][21];
vector<int> Vec;

int go(int idx, int visited, int weight) {
    if (idx == M)
        return 0;

    int &ret = DP[idx][visited][weight];
    if (ret)
        return ret;

    //아무것도 안담을 경우
    ret = max(ret, go(idx + 1, visited, C));
    for (int n = 0; n < N; ++n) {
        if (visited & (1 << n))
            continue;
        if (weight - Vec[n] < 0)
            continue;

        ret = max(ret, go(idx, visited | (1 << n), weight - Vec[n]) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> C;
    Vec = vector<int>(N);

    for (int n = 0; n < N; ++n)
        cin >> Vec[n];

    cout << go(0, 0, C) << '\n';
    return 0;
}