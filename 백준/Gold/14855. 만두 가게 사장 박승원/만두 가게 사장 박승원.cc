#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, A[11], B[11], C[11], D[11], DP[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> C[0] >> D[0];

    for (int i = 0; i <= N; ++i)
        DP[i] = (i / C[0]) * D[0];

    for (int m = 1; m <= M; ++m)
        cin >> A[m] >> B[m] >> C[m] >> D[m];

    for (int m = 1; m <= M; ++m) {
        int a = A[m], b = B[m];
        int ab = a / b;

        for (int i = 0; i < ab; ++i) {
            for (int j = N; j >= C[m]; --j)
                DP[j] = max(DP[j], DP[j - C[m]] + D[m]);
        }
    }

    int ret = 0;
    for (int i = 0; i <= N; ++i)
        ret = max(ret, DP[i]);

    cout << ret << '\n';

    return 0;
}