#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

int N;
ll K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    vector<ll> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n];

    sort(vec.begin(), vec.end());

    ll ret = INT64_MAX;
    for (int i = 1; i <= N - 1; ++i) {
        ll a = vec[0] * i, b = vec[i] * (N - i);
        ll sum = K / (a + b);
        if (K % (a + b))
            sum += 1;

        ret = min(ret, sum);
    }

    cout << ret << '\n';

    return 0;
}