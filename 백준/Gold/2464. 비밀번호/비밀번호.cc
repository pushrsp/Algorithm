#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A;

    ll temp = A;
    string bit;
    while (temp > 0) {
        bit = to_string(temp & 1) + bit;
        temp >>= 1;
    }

    string lower = bit;
    string higher = "0" + bit;

    ll l = 0, h = 0;

    prev_permutation(lower.begin(), lower.end());
    for (int i = 0; i < lower.length(); ++i)
        l += (lower[lower.length() - i - 1] - '0') * (1LL << i);

    if (l == A)
        l = 0;

    next_permutation(higher.begin(), higher.end());
    for (int i = 0; i < higher.length(); ++i)
        h += (higher[higher.length() - i - 1] - '0') * (1LL << i);

    cout << l << ' ' << h << '\n';
    
    return 0;
}