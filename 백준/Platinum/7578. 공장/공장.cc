#include <iostream>
#include <vector>
#include <cmath>

#define MAX 500001
#define ll long long

using namespace std;

int N, A[MAX], Pos[1000001];
vector<ll> SegTree;

void Update(int node, int from, int to, int idx) {
    if (to < idx || idx < from)
        return;
    if (from == to) {
        SegTree[node] = 1;
        return;
    }

    int mid = (from + to) / 2;
    Update(2 * node, from, mid, idx), Update(2 * node + 1, mid + 1, to, idx);
    SegTree[node] = SegTree[2 * node] + SegTree[2 * node + 1];
}

ll Sum(int node, int from, int to, int left, int right) {
    if (to < left || right < from)
        return 0;
    if (left <= from && to <= right)
        return SegTree[node];

    int mid = (from + to) / 2;
    return Sum(2 * node, from, mid, left, right) + Sum(2 * node + 1, mid + 1, to, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int h = static_cast<int>(::ceil(::log2(N)));
    SegTree = vector<ll>(1 << (h + 1));

    for (int n = 0; n < N; ++n)
        cin >> A[n];

    int num;
    for (int n = 0; n < N; ++n) {
        cin >> num;
        Pos[num] = n;
    }

    ll ret = 0;
    for (int n = 0; n < N; ++n) {
        int i = Pos[A[n]];
        ret += Sum(1, 0, N - 1, i + 1, N - 1);
        Update(1, 0, N - 1, i);
    }

    cout << ret << '\n';

    return 0;
}