#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;
ll W, Sum3[250001], Sum5[250001];
vector<ll> V3, V5;

ll desc(const ll &a, const ll &b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> W;

    int a, b;
    for (int n = 0; n < N; ++n) {
        cin >> a >> b;
        if (a == 3)
            V3.push_back(b);
        else
            V5.push_back(b);
    }

    sort(V3.begin(), V3.end(), desc);
    sort(V5.begin(), V5.end(), desc);

    for (int i = 0; i < V3.size(); ++i)
        Sum3[i + 1] = V3[i] + Sum3[i];
    for (int i = 0; i < V5.size(); ++i)
        Sum5[i + 1] = V5[i] + Sum5[i];

    ll ret = 0;
    for (ll i = 0; i <= V3.size(); ++i) {
        if (i * 3 <= W) {
            ll five = (W - (i * 3)) / 5;
            if (five <= V5.size())
                ret = max(ret, Sum3[i] + Sum5[five]);
            else
                ret = max(ret, Sum3[i] + Sum5[V5.size()]);
        }
    }

    cout << ret << '\n';

    return 0;
}