#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int N, A[1001], DP[1001][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    for (int n = 1; n <= N; ++n) {
        DP[n][0] = A[n];
        DP[n][1] = 1;

        for (int i = 1; i < n; ++i) {
            if (A[n] <= DP[i][0]) {
                if (DP[n][1] <= DP[i][1] + 1) {
                    DP[n][1] = DP[i][1] + 1;
                    DP[n][0] = DP[i][0] + A[n];
                }
            }
        }
    }

    int ret = 1;
    for (int n = 1; n <= N; ++n)
        ret = max(ret, DP[n][1]);

    cout << ret << '\n';

    return 0;
}