#include <iostream>
#include <algorithm>

#define MAX 101
#define TOTAL 10001

using namespace std;

int N, M, A[MAX], C[MAX];
int DP[MAX][TOTAL];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int i = 1; i <= N; ++i)
        cin >> C[i];

    int ret = TOTAL;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < TOTAL; ++j) {
            if (C[i] <= j)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - C[i]] + A[i]);
            else
                DP[i][j] = DP[i - 1][j];

            if (DP[i][j] >= M)
                ret = min(ret, j);
        }
    }

    cout << ret << '\n';
    return 0;
}