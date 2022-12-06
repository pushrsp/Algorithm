#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

ll N, DP[21][101];
vector<ll> Nums;

ll go(ll count, ll sum) {
    if (sum < 0 || sum > 20)
        return 0;

    if (count == N - 2) {
        if (sum == Nums.back())
            return 1;

        return 0;
    }

    ll &ret = DP[sum][count];
    if (ret)
        return ret;

    ret += go(count + 1, sum + Nums[count + 1]);
    ret += go(count + 1, sum - Nums[count + 1]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Nums = vector<ll>(N);

    for (int n = 0; n < N; ++n)
        cin >> Nums[n];

    cout << go(0, Nums[0]) << '\n';

    return 0;
}