#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int T, N, DP[501][501], File[501], Sum[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> File[i];
            Sum[i] = Sum[i - 1] + File[i];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N - i; j++) {
                DP[j][i + j] = INF;
                for (int k = j; k < i + j; k++)
                    DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + Sum[i + j] - Sum[j - 1]);
            }
        }

        cout << DP[1][N] << endl;
    }
    return 0;
}