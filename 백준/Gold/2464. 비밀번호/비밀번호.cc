#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int OneCnt;
ll A, Mask = 3, One = 1, L, H;

void find_min() {
    L = A ^ Mask;
    L = L / One * One;
    ll n = (One >> 1);

    int cnt = OneCnt;
    while (n && cnt--) {
        L += n;
        n >>= 1;
    }
}

void find_max() {
    H = A ^ Mask;
    H = H / One * One;
    ll n = 1;

    int cnt = OneCnt;
    while (n < One && cnt--) {
        H += n;
        n <<= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A;

    while (true) {
        if (L && H)
            break;
        if (One > A)
            break;

        if ((A & Mask) == (One << 1))
            find_min();
        if ((A & Mask) == One)
            find_max();
        if (A & One)
            OneCnt++;

        One <<= 1;
        Mask <<= 1;
    }

    cout << L << ' ' << H << '\n';

    return 0;
}