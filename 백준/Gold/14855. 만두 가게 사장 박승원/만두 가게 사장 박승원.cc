#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;
int A[1001], B[1001], C[1001], D[1001], Bound[1001], DP[100001][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> C[0] >> D[0];
    for (int i = 1; i <= M; ++i)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    Bound[0] = N / C[0];
    for (int i = 1; i <= M; ++i)
        Bound[i] = min(A[i] / B[i], N / C[i]);

    int idx = 1, ret = 0;
    for (int i = 0; i <= M; ++i) {
        for (int j = 1; j <= Bound[i]; ++j) {
            for (int k = N; k >= 0; --k) {
                if (C[i] <= k)
                    DP[idx][k] = max(DP[idx - 1][k], DP[idx - 1][k - C[i]] + D[i]);
                else
                    DP[idx][k] = DP[idx - 1][k];

                ret = max(ret, DP[idx][k]);
            }
            idx++;
        }
    }

    cout << ret << '\n';
    return 0;
}