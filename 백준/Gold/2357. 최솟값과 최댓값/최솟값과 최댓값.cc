#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAX 100001

using namespace std;

int N, M, Arr[MAX];
vector<int> Seg1, Seg2;

int InitMin(int node, int start, int end) {
    if (start == end)
        return Seg1[node] = Arr[start];

    int mid = (start + end) / 2;
    return Seg1[node] = min(InitMin(node * 2, start, mid), InitMin(node * 2 + 1, mid + 1, end));
}

int InitMax(int node, int start, int end) {
    if (start == end)
        return Seg2[node] = Arr[start];

    int mid = (start + end) / 2;
    return Seg2[node] = max(InitMax(node * 2, start, mid), InitMax(node * 2 + 1, mid + 1, end));
}

int QueryMin(int node, int from, int to, int left, int right) {
    if (to < left || right < from)
        return INT32_MAX;
    if (left <= from && to <= right)
        return Seg1[node];

    int mid = (from + to) / 2;
    return min(QueryMin(node * 2, from, mid, left, right), QueryMin(node * 2 + 1, mid + 1, to, left, right));
}

int QueryMax(int node, int from, int to, int left, int right) {
    if (to < left || right < from)
        return INT32_MIN;
    if (left <= from && to <= right)
        return Seg2[node];

    int mid = (from + to) / 2;
    return max(QueryMax(node * 2, from, mid, left, right), QueryMax(node * 2 + 1, mid + 1, to, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> Arr[i];

    int h = static_cast<int>(::ceil(::log2(N)));
    Seg1 = vector<int>(1 << (h + 1));
    Seg2 = vector<int>(1 << (h + 1));

    InitMin(1, 0, N - 1);
    InitMax(1, 0, N - 1);

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        cout << QueryMin(1, 0, N - 1, a - 1, b - 1) << ' ' << QueryMax(1, 0, N - 1, a - 1, b - 1) << '\n';
    }
    return 0;
}