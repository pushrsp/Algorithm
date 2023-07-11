#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, N, M, K, Arr[100001], DP[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> M >> K;

        ::memset(Arr, 0, sizeof(Arr));
        ::memset(DP, 0, sizeof(DP));

        for (int n = 1; n <= N; ++n) {
            cin >> Arr[n];
            DP[n] += DP[n - 1] + Arr[n];
        }

        if (N == M) {
            if (DP[N] < K)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            
            continue;
        }

        for (int i = 1; i < M; ++i)
            DP[i + N] = DP[i + N - 1] + Arr[i];

        int ret = 0, left = 1, right = M;
        while (right <= N + M - 1) {
            if (DP[right] - DP[left - 1] < K)
                ret += 1;

            right++, left++;
        }

        cout << ret << '\n';
    }
    return 0;
}