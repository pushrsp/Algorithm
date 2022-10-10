#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int N, M;
vector<ll> Money;

bool is_valid(ll mid) {
    int cnt = 0;
    ll sum = 0;
    for (ll &money: Money) {
        if (money > mid)
            return false;

        if (sum + money > mid) {
            sum = 0;
            cnt++;
        }
        sum += money;
    }

    if (sum != 0)
        cnt++;

    return cnt <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    ll right = 0;
    Money = vector<ll>(N);
    for (int n = 0; n < N; ++n)
        cin >> Money[n], right += Money[n];

    ll left = 1, mid, ret = INT32_MAX;
    while (left <= right) {
        mid = (left + right) / 2;

        if (is_valid(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}