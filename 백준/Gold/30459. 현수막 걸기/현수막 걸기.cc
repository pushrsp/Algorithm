#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int N, M;
ll R;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> R;

    vector<int> a(N);
    for (int n = 0; n < N; ++n)
        cin >> a[n];

    sort(a.begin(), a.end());

    vector<int> b(M);
    for (int m = 0; m < M; ++m)
        cin >> b[m];

    set<int> s;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j)
            s.insert(abs(a[j] - a[i]));
    }

    vector<int> aa(s.begin(), s.end());
    sort(aa.begin(), aa.end());

    ll r = R * 2, ret = -1;
    for (auto &h: b) {
        int idx = upper_bound(aa.begin(), aa.end(), r / h) - aa.begin() - 1;
        if (idx == -1)
            continue;

        ret = max(ret, (ll) aa[idx] * h);
    }

    if (ret == -1) {
        cout << -1 << '\n';
        return 0;
    }


    cout << fixed;
    cout.precision(1);

    cout << (double) ret / 2 << '\n';

    return 0;
}