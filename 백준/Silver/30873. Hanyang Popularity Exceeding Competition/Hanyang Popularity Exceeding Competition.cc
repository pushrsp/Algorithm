#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

int N, DP[200001][2];
vector<pair<int, int>> P;

int go(int n, int meet, int p) {
    if (n >= N)
        return 0;

    int &ret = DP[n][meet];
    if (ret != -1)
        return ret;

    ret = 0;

    if (abs(P[n].first - p) <= P[n].second) //현재 유명인을 만날 수 있는지
        ret = max(ret, go(n + 1, 1, p + 1) + 1); //현재 유명인을 만날건지

    ret = max(ret, go(n + 1, 0, p)); //현재 유명인을 스킵할건지

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int p, c;
    for (int n = 0; n < N; ++n) {
        cin >> p >> c;
        P.emplace_back(p, c);
    }

    ::memset(DP, -1, sizeof(DP));

    cout << go(0, 0, 0) << '\n';

    return 0;
}