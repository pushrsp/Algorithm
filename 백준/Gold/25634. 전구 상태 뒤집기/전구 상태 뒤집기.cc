#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int N, A[200001], B[200001], DP[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int mn = INT32_MAX;
    for (int n = 0; n < N; ++n) {
        cin >> A[n];
        mn = min(mn, A[n]);
    }

    int ret = 0;
    for (int n = 0; n < N; ++n) {
        cin >> B[n];

        if (B[n])
            ret += A[n];
    }

    int sum = 0, mx = 0;
    for (int n = 0; n < N; ++n) {
        if (B[n])
            sum -= A[n];
        else
            sum += A[n];

        sum = max(sum, 0);
        mx = max(mx, sum);
    }

    if (mx == 0)
        cout << ret - mn << '\n';
    else
        cout << ret + mx << '\n';

    return 0;
}