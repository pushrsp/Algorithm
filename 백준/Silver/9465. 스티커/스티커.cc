#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 100001

using namespace std;

int T, N, Arr[3][MAX];
int DP[3][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        for (int y = 1; y <= 2; ++y) {
            for (int x = 1; x <= N; ++x) {
                cin >> Arr[y][x];
            }
        }

        DP[1][1] = Arr[1][1];
        DP[2][1] = Arr[2][1];

        for (int i = 2; i <= N; ++i) {
            DP[1][i] = max(DP[2][i - 1], DP[2][i - 2]) + Arr[1][i];
            DP[2][i] = max(DP[1][i - 1], DP[1][i - 2]) + Arr[2][i];
        }

        cout << max(DP[1][N], DP[2][N]) << '\n';

        ::memset(DP, 0, sizeof(DP));
    }

    return 0;
}