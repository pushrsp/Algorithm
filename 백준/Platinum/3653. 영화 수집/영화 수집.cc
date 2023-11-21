#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, M, SegTree[800001], Idx[100001];

void update(int node, int start, int end, int idx, int value) {
    if (start <= idx && idx <= end) {
        SegTree[node] += value;
        if (start != end) {
            int mid = (start + end) / 2;
            update(2 * node, start, mid, idx, value);
            update(2 * node + 1, mid + 1, end, idx, value);
        }
    }
}

int sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return SegTree[node];

    int mid = (start + end) / 2;
    return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> M;

        ::memset(SegTree, 0, sizeof(SegTree));
        ::memset(Idx, 0, sizeof(Idx));

        for (int n = 1; n <= N; ++n) {
            Idx[n] = M + n;
            update(1, 1, N + M, M + n, 1);
        }

        int dvd, next = M;
        for (int m = 1; m <= M; ++m) {
            cin >> dvd;
            cout << sum(1, 1, N + M, 1, Idx[dvd] - 1) << ' ';

            update(1, 1, N + M, Idx[dvd], -1);
            Idx[dvd] = next--;
            update(1, 1, N + M, Idx[dvd], 1);
        }

        cout << '\n';
    }
    return 0;
}