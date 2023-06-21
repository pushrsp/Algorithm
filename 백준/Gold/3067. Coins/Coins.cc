#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, N, M, Coins[21], DP[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        ::memset(Coins, 0, sizeof(Coins));
        ::memset(DP, 0, sizeof(DP));

        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> Coins[i];

        cin >> M;

        DP[0] = 1;
        for (int n = 1; n <= N; ++n) {
            int coin = Coins[n];

            for (int m = 1; m <= M; ++m) {
                if (m - coin >= 0)
                    DP[m] += DP[m - coin];
            }
        }

        cout << DP[M] << '\n';
    }
    return 0;
}