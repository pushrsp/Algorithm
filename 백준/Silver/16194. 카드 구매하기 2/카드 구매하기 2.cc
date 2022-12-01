#include <iostream>
#include <vector>

using namespace std;

int N, P[1001], DP[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> P[i];

    DP[1] = P[1];
    for (int i = 2; i <= N; ++i) {
        DP[i] = P[i];

        for (int j = 1; j <= i; ++j)
            DP[i] = min(DP[i], DP[i - j] + P[j]);
    }

    cout << DP[N] << '\n';
    return 0;
}