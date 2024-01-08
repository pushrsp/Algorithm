#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int N;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return abs(a.first) < abs(b.first);

    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end(), cmp);

    cout << vec[0].first << ' ' << vec[0].second;

    return 0;
}