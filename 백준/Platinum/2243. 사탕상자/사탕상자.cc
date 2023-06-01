#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000001
#define ll long long

using namespace std;

int N, Arr[MAX];
vector<ll> SegTree;

ll Query(int node, int from, int to, int val) {
    if (from == to)
        return to;

    int mid = (from + to) / 2;
    if (SegTree[2 * node] >= val)
        return Query(2 * node, from, mid, val);

    return Query(2 * node + 1, mid + 1, to, val - SegTree[2 * node]);
}

void Update(int node, int from, int to, int idx, int diff) {
    if (idx < from || idx > to)
        return;
    if (from == to) {
        SegTree[node] = diff;
        return;
    }

    int mid = (from + to) / 2;
    Update(2 * node, from, mid, idx, diff), Update(2 * node + 1, mid + 1, to, idx, diff);
    SegTree[node] = SegTree[2 * node] + SegTree[2 * node + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int h = static_cast<int>(::ceil(::log2(MAX)));
    SegTree = vector<ll>(1 << (h + 1));

    int a, b, c;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;

        if (a == 1) {
            ll k = Query(1, 1, MAX, b);
            cout << k << '\n';
            Update(1, 1, MAX, k, Arr[k] - 1);
            Arr[k] -= 1;
        } else {
            cin >> c;
            Update(1, 1, MAX, b, Arr[b] + c);
            Arr[b] += c;
        }
    }


    return 0;
}