#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

#define ll long long

using namespace std;

int N, A[100001], B[100001], I[100001], L[100001], S[100001], G[100001];
int Seg[400001];

void clear() {
    for (int i = 0; i < 400001; ++i)
        Seg[i] = 0;
}

int update(int node, int s, int e, int target, int num) {
    if (target < s || e < target)
        return Seg[node];
    if (s == e)
        return Seg[node] += num;

    int mid = (s + e) / 2;
    return Seg[node] = update(node * 2, s, mid, target, num) + update(node * 2 + 1, mid + 1, e, target, num);
}

int query(int node, int s, int e, int l, int r) {
    if (e < l || r < s)
        return 0;
    if (l <= s && e <= r)
        return Seg[node];

    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 0; n < N; ++n)
        cin >> A[n];
    for (int n = 0; n < N; ++n)
        cin >> B[n];

    for (int n = 0; n < N; ++n)
        I[A[n]] = n;
    for (int n = 0; n < N; ++n)
        L[n] = I[B[n]] + 1;

    for (int n = 0; n < N; ++n) {
        S[n] = query(1, 1, N, 1, L[n] - 1);
        update(1, 1, N, L[n], 1);
    }

    clear();

    for (int n = N - 1; n >= 0; --n) {
        G[n] = query(1, 1, N, L[n] + 1, N);
        update(1, 1, N, L[n], 1);
    }

    ll ret = 0;
    for (int n = 0; n < N; ++n)
        ret += S[n] * G[n];

    if (ret == 0)
        cout << "Attention is what I want" << '\n';
    else
        cout << "My heart has gone to paradise" << '\n' << ret << '\n';

    return 0;
}