#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, C[31];
bool DP[40001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    DP[0] = true;
    for (int n = 1; n <= N; ++n) {
        cin >> C[n];

        for (int i = 40000; i >= 0; --i) {
            if (DP[i])
                DP[i + C[n]] = true;
        }

        for (int i = 0; i <= 40000; ++i) {
            if (DP[i])
                DP[::abs(i - C[n])] = true;
        }
    }

    cin >> M;

    int n;
    for (int m = 0; m < M; ++m) {
        cin >> n;

        if (DP[n])
            cout << 'Y' << ' ';
        else
            cout << 'N' << ' ';
    }

    return 0;
}