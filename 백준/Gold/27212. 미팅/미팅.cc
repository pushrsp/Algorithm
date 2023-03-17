#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

int N, M, C, A[1001], B[1001];
ll W[17][17], DP[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> C;

    for (int y = 1; y <= C; ++y) {
        for (int x = 1; x <= C; ++x) {
            cin >> W[y][x];
        }
    }

    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int i = 1; i <= M; ++i)
        cin >> B[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            DP[i][j] = max(DP[i - 1][j - 1] + W[A[i]][B[j]], max(DP[i - 1][j], DP[i][j - 1]));
        }
    }

    cout << DP[N][M] << '\n';
    return 0;
}