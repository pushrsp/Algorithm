#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, Q, Arr[2001][2001], Sum[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> Q;

    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            cin >> Arr[n][m];
            Sum[n][m] = Sum[n - 1][m] + Arr[n][m];
        }
    }

    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            Sum[n][m] += Sum[n - 1][m - 1];
        }
    }

    int a, b;
    for (int q = 0; q < Q; ++q) {
        cin >> a >> b;

        cout << Sum[a][b] << '\n';
    }
    return 0;
}