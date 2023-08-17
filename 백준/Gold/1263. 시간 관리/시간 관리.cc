#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first > b.first;

    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end(), cmp_pair);

    int prev = vec[0].second;
    for (int i = 0; i < N; ++i) {
        if (prev > vec[i].second)
            prev = vec[i].second;

        prev -= vec[i].first;
    }

    if (prev >= 0)
        cout << prev << '\n';
    else
        cout << -1 << '\n';

    return 0;
}