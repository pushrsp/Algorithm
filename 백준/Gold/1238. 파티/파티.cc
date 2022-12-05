#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 200000000
#define ll long long

using namespace std;

int N, M, X;
vector<vector<int>> Adj;

void Floyd() {
    for (int n = 0; n < N; ++n) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                Adj[i][j] = min(Adj[i][j], Adj[i][n] + Adj[n][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> X;

    X--;
    Adj = vector<vector<int>>(N, vector<int>(N, INF));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        a--, b--;
        Adj[a][b] = c;
    }

    Floyd();
    Adj[X][X] = 0;

    int answer = 0;
    for (int i = 0; i < N; ++i)
        answer = max(answer, Adj[i][X] + Adj[X][i]);

    cout << answer << '\n';
    return 0;
}