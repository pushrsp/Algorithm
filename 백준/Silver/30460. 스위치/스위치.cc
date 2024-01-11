#include <iostream>
#include <vector>
#include <set>
#include <cstring>

#define ll long long

using namespace std;

int N, A[200005], DP[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    fill(DP, DP + 200005, INT32_MIN);

    DP[0] = 0;
    for (int n = 1; n <= N + 2; ++n) {
        DP[n] = max(DP[n], DP[n - 1] + A[n]);

        if (n >= 3)
            DP[n] = max(DP[n], DP[n - 3] + (A[n - 2] + A[n - 1] + A[n]) * 2);
    }

    cout << DP[N + 2] << '\n';

    return 0;
}