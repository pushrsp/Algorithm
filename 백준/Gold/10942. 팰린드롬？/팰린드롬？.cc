#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> Pal;
bool DP[2001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Pal = vector<int>(N + 2);

    for (int n = 1; n <= N; ++n)
        cin >> Pal[n];
    for (int n = 1; n <= N; ++n)
        DP[n][n] = true;
    for (int n = 1; n <= N; ++n) {
        if (Pal[n] == Pal[n + 1])
            DP[n][n + 1] = true;
    }

    for (int n = 2; n <= N; ++n) {
        for (int i = 1; i <= N - n; ++i) {
            if (Pal[i] == Pal[i + n] && DP[i + 1][i + n - 1])
                DP[i][i + n] = true;
        }
    }

    cin >> M;

    for (int m = 0; m < M; ++m) {
        int start, end;
        cin >> start >> end;

        cout << DP[start][end] << '\n';
    }
    return 0;
}