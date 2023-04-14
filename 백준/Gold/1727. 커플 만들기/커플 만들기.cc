#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAX 1001
#define ll long long

using namespace std;

int N, M, Man[MAX], Woman[MAX];
ll DP[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> Man[i];
    for (int i = 0; i < M; ++i)
        cin >> Woman[i];

    sort(Man, Man + N);
    sort(Woman, Woman + M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            DP[i][j] = DP[i - 1][j - 1] + ::abs(Man[i - 1] - Woman[j - 1]);

            if (i < j)
                DP[i][j] = min(DP[i][j], DP[i][j - 1]);
            else if (i > j)
                DP[i][j] = min(DP[i][j], DP[i - 1][j]);
        }
    }

    cout << DP[N][M] << '\n';
    return 0;
}