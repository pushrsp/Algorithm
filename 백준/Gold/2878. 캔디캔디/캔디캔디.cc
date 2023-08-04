#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

ll N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> M >> N;

    ll sum = -M;
    vector<ll> vec(N);
    for (int n = 0; n < N; ++n) {
        cin >> vec[n];
        sum += vec[n];
    }

    sort(vec.begin(), vec.end());

    ll ret = 0;
    for (int i = 0; i < N; ++i) {
        ll t = min(vec[i], sum / (N - i));
        ret += t * t;
        sum -= t;
    }

    cout << ret << '\n';

    return 0;
}