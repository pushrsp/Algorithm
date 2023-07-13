#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, N, M, DP[10001], Arr[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        ::memset(DP, 0, sizeof(DP));
        ::memset(Arr, 0, sizeof(Arr));

        for (int n = 1; n <= N; ++n)
            cin >> Arr[n];

        cin >> M;

        DP[0] = 1;
        for (int n = 1; n <= N; ++n) {
            for (int m = 1; m <= M; ++m) {
                if (m - Arr[n] >= 0)
                    DP[m] += DP[m - Arr[n]];
            }
        }

        cout << DP[M] << '\n';
    }
    return 0;
}