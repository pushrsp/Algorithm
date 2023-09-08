#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define ll long long

using namespace std;

int N, S, A[41];

void go(int s, int e, ll sum, unordered_map<ll, ll> &m) {
    if (s == e + 1) {
        m[sum]++;
        return;
    }

    go(s + 1, e, sum + A[s], m);
    go(s + 1, e, sum, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    unordered_map<ll, ll> m1, m2;

    int half = N / 2;
    go(1, half, 0, m1);
    go(half + 1, N, 0, m2);


    ll ret = 0;
    for (auto &p: m1) {
        if (m2.find(S - p.first) != m2.end())
            ret += p.second * m2[S - p.first];
    }

    if (S == 0)
        cout << ret - 1 << '\n';
    else
        cout << ret << '\n';

    return 0;
}