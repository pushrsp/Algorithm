#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, DP[5][5][100001];
vector<int> Vec;

int GetCount(int from, int to) {
    if (from == 0)
        return 2;
    if (from == to)
        return 1;
    if (abs(from - to) == 2)
        return 4;
    return 3;
}

int go(int left, int right, int idx) {
    if (idx == Vec.size())
        return 0;
    if (DP[left][right][idx] != -1)
        return DP[left][right][idx];

    int l = go(Vec[idx], right, idx + 1) + GetCount(left, Vec[idx]);
    int r = go(left, Vec[idx], idx + 1) + GetCount(right, Vec[idx]);

    return DP[left][right][idx] = min(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> N;

        if (N == 0)
            break;

        Vec.push_back(N);
    }

    memset(DP, -1, sizeof(DP));
    cout << go(0, 0, 0) << '\n';
    return 0;
}