#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll a, b, mid, ret;

int main() {
    cin >> a >> b;
    
    ll z = b * 100 / a;
    ll lo = 0, hi = INT32_MAX;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if ((b + mid) * 100 / (a + mid) > z) {
            ret = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (ret)
        cout << ret << '\n';
    else
        cout << -1 << '\n';

    return 0;
}