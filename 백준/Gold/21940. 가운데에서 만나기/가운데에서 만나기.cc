#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, M, K, Adj[201][201];

void floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (Adj[i][j] > Adj[i][k] + Adj[k][j])
                    Adj[i][j] = Adj[i][k] + Adj[k][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int n = 0; n <= N; ++n) {
        for (int i = 0; i <= N; ++i)
            if (n != i)
                Adj[n][i] = INF;
    }

    int a, b, c;
    for (int m = 0; m < M; ++m) {
        cin >> a >> b >> c;
        Adj[a][b] = c;
    }

    cin >> K;

    vector<int> friends(K);
    for (int k = 0; k < K; ++k)
        cin >> friends[k];

    floyd();

    vector<int> vec;
    int ret = INF;
    for (int n = 1; n <= N; ++n) {
        int dist = 0;
        for (auto &city: friends) {
            if (Adj[n][city] != INF && Adj[city][n] != INF)
                dist = max(dist, Adj[n][city] + Adj[city][n]);
        }

        if (ret > dist) {
            ret = dist;
            vec.clear();
            vec.push_back(n);
        } else if (ret == dist) {
            vec.push_back(n);
        }
    }

    sort(vec.begin(), vec.end());

    for (auto &city: vec)
        cout << city << ' ';
    cout << '\n';

    return 0;
}