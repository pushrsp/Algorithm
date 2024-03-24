#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N, T;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    vector<pair<ll, ll>> v(N);
    for (int n = 0; n < N; ++n)
        cin >> v[n].first >> v[n].second;

    sort(v.begin(), v.end(), cmp);

    ll ret = 0, day = T - N;
    for (auto &p: v) {
        ret += p.first + (p.second * day);
        day++;
    }

    cout << ret << '\n';

    return 0;
}