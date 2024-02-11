#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<int> vec(N);

    ll sum = 0, mx = 0;
    for (int n = 0; n < N; ++n) {
        cin >> vec[n];
        sum += vec[n];

        mx = max(mx, (ll) vec[n]);
    }

    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    ll a = sum % 2 ? sum / 2 + 1 : sum / 2;
    if (a < mx)
        cout << (sum - mx) * 2 + 1 << '\n';
    else
        cout << sum << '\n';

    return 0;
}