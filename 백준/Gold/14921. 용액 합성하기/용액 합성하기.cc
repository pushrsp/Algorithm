#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N;

ll get_diff(ll a, ll b) {
    return abs(a + b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    map<ll, int> m;
    vector<ll> v(N);
    for (int n = 0; n < N; ++n) {
        cin >> v[n];
        m[v[n]]++;
    }

    ll ret = INT64_MAX, offset = INT64_MAX;
    for (auto &n: v) {
        int i = lower_bound(v.begin(), v.end(), -n) - v.begin();
        if (i == N)
            i--;

        if (n == v[i]) {
            if (m[n] > 1) {
                ll diff = get_diff(n, v[i]);
                if (diff < offset) {
                    offset = diff;
                    ret = n + v[i];
                }
            }
        } else {
            ll diff = get_diff(n, v[i]);
            if (diff < offset) {
                offset = diff;
                ret = n + v[i];
            }
        }

        if (i != 0) {
            if (n == v[i - 1]) {
                if (m[n] > 1) {
                    ll diff = get_diff(n, v[i - 1]);
                    if (diff < offset) {
                        offset = diff;
                        ret = n + v[i - 1];
                    }
                }
            } else {
                ll diff = get_diff(n, v[i - 1]);
                if (diff < offset) {
                    offset = diff;
                    ret = n + v[i - 1];
                }
            }
        }
    }

    cout << ret << '\n';

    return 0;
}