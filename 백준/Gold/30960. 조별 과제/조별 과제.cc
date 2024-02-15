#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

int N, A[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    sort(A + 1, A + 1 + N);

    ll x = 0, y = INT64_MAX;
    for (int n = 2; n <= N - 1; n += 2) {
        x += A[n] - A[n - 1];
        y = min(y, x) + A[n + 1] - A[n];
    }

    cout << y << '\n';

    return 0;
}