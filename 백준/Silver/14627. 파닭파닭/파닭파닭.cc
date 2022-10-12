#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int S, C;
vector<ll> Arr;

bool is_valid(ll mid) {
    ll cnt = 0;
    for (ll &arr: Arr)
        cnt += arr / mid;

    return cnt >= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> C;

    ll sum = 0;
    Arr = vector<ll>(S);
    for (int s = 0; s < S; ++s)
        cin >> Arr[s], sum += Arr[s];

    ll left = 0, right = INT32_MAX, mid, ret;
    while (left <= right) {
        mid = (left + right) / (1LL * 2);

        if (is_valid(mid)) {
            ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << sum - ret * C << '\n';
    return 0;
}