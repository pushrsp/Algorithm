#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define MAX 501

using namespace std;

int N, M;
bool Adj[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        Adj[a][b] = true;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (Adj[i][k] && Adj[k][j])
                    Adj[i][j] = true;
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        int count = 0;
        for (int j = 1; j <= N; ++j) {
            if (Adj[i][j] || Adj[j][i])
                count++;
        }

        if (count == N - 1)
            ret += 1;
    }

    cout << ret << '\n';
    return 0;
}