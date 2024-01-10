#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, A[500001];

bool asc(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    sort(A, A + N + 1);

    ll x = 0, y = INT64_MAX;
    for (int n = 2; n <= N; n += 2) {
        x += A[n] - A[n - 1];
        y = min(y, x) + A[n + 1] - A[n];
    }

    cout << y << '\n';

    return 0;
}