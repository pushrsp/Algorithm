#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

int N, DP[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    if (N % 2) {
        cout << 0 << '\n';
        return 0;
    }

    DP[0] = 1;
    DP[2] = 3;
    DP[4] = 11;

    for (int i = 6; i <= N; i += 2) {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j -= 2)
            DP[i] += DP[j] * 2;
    }

    cout << DP[N] << '\n';

    return 0;
}