#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define ll long long
#define INF 987654321

using namespace std;

int N, M, Adj[101][101];

void Floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                Adj[i][j] = min(Adj[i][j], Adj[i][k] + Adj[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j)
                Adj[i][j] = 0;
            else
                Adj[i][j] = INF;
        }
    }

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        Adj[a][b] = min(Adj[a][b], c);
    }

    Floyd();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Adj[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << Adj[i][j] << ' ';
        }

        cout << '\n';
    }
    return 0;
}