#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
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

    int ret = vec[0].second;
    for (int n = 0; n < N; ++n) {
        if (ret > vec[n].second)
            ret = vec[n].second;

        ret -= vec[n].first;
    }

    if (ret >= 0)
        cout << ret << '\n';
    else
        cout << -1 << '\n';

    return 0;
}