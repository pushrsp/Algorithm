#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 2000000000
#define ll long long

using namespace std;

int N, Arr[100001], SegTree[1000001];
ll Answer;

ll InitMin(int node, int from, int to) {
    if (from == to)
        return SegTree[node] = from;

    int mid = (from + to) / 2;
    int left = InitMin(2 * node, from, mid);
    int right = InitMin(2 * node + 1, mid + 1, to);

    return SegTree[node] = Arr[left] < Arr[right] ? left : right;
}

ll QueryMin(int node, int from, int to, int left, int right) {
    if (to < left || right < from)
        return INF;
    if (left <= from && to <= right)
        return SegTree[node];

    int mid = (from + to) / 2;
    ll lleft = QueryMin(2 * node, from, mid, left, right);
    ll rright = QueryMin(2 * node + 1, mid + 1, to, left, right);

    if (lleft == INF)
        return rright;
    else if (rright == INF)
        return lleft;

    return Arr[lleft] < Arr[rright] ? lleft : rright;
}

void Solve(int left, int right) {
    if (left > right)
        return;

    ll index = QueryMin(1, 0, N - 1, left, right);
    Answer = max(Answer, (ll) (Arr[index] * (right - left + 1)));

    Solve(left, index - 1), Solve(index + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> Arr[i];

    InitMin(1, 0, (int) N - 1);
    Solve(0, N - 1);

    cout << Answer << '\n';

    return 0;
}