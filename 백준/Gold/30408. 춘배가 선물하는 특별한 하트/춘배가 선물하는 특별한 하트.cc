#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

ll N, M;
set<ll> S;

void go(ll n) {
    if (n == 1)
        return;

    S.insert(n);

    if (n % 2) {
        ll h = (n - 1) / 2;

        if (S.find(h) == S.end())
            go(h);

        if (S.find(n - h) == S.end())
            go(n - h);
    } else {
        if (S.find(n / 2) == S.end())
            go(n / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    if (M == 1) {
        cout << "YES" << '\n';
        return 0;
    }

    go(N);
    S.insert(N);

    if (S.find(M) != S.end())
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}