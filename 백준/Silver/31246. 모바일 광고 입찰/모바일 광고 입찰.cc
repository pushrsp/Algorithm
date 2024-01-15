#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int N, K;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.first - a.second > b.first - b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    vector<pair<ll, ll>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end(), cmp);

    int k = 0;
    ll x = 0;
    for (auto &p: vec) {
        if (p.first + x < p.second)
            x += p.second - p.first - x;

        k += 1;

        if (k >= K) {
            cout << x << '\n';
            return 0;
        }
    }

    return 0;
}