#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#define ll long long
#define MAX 10001

using namespace std;

ll L, K, C, Pos[MAX];

ll Search(ll target) {
    ll count = C;
    ll from = L;

    for (int i = K - 1; i >= 0 && count > 0; --i) {
        if (from - Pos[i] > target) {
            if (Pos[i + 1] - Pos[i] > target)
                return -1;

            count--;
            from = Pos[i + 1];
        }
    }

    if (count > 0)
        from = Pos[0];

    if (from > target)
        return -1;

    return from;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> L >> K >> C;
    for (int i = 0; i < K; ++i)
        cin >> Pos[i];

    sort(Pos, Pos + K);

    int j = 0;
    for (int i = 0; i < K; ++i) {
        Pos[j] = Pos[i];

        if (Pos[i] != Pos[i + 1])
            j++;
    }

    K = j;
    Pos[K] = L;

    ll left = 0, right = L * 2, mid, ret;
    while (left <= right) {
        mid = (left + right) / 2;

        if (Search(mid) >= 1) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << ' ' << Search(ret) << '\n';

    return 0;
}