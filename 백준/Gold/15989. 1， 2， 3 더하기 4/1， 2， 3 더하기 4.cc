#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, DP[10001][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        DP[0][1] = 1, DP[1][1] = 1;
        for (int n = 2; n <= N; ++n) {
            DP[n][1] = DP[n - 1][1];
            DP[n][2] = DP[n - 2][1] + DP[n - 2][2];
            if (n >= 3)
                DP[n][3] = DP[n - 3][1] + DP[n - 3][2] + DP[n - 3][3];
        }

        cout << DP[N][1] + DP[N][2] + DP[N][3] << '\n';
    }
    return 0;
}