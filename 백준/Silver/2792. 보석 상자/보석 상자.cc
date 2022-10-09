#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll N, M, Arr[300001];

bool is_valid(ll mid) {
    ll cmp = 0;
    for (int m = 0; m < M; ++m) {
        cmp += Arr[m] / mid;

        if (Arr[m] % mid)
            cmp++;
    }

    return cmp <= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    ll left = 1, right = 0, mid = 0;
    for (int m = 0; m < M; ++m) {
        cin >> Arr[m];
        right = max(right, Arr[m]);
    }

    ll ret = INT32_MAX;
    while (left <= right) {
        mid = (left + right) / 2;

        if (is_valid(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}