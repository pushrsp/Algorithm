#include <iostream>
#include <queue>
#include <cmath>

#define MAX 100001

using namespace std;

int N, R, Q, DP[MAX];
vector<int> Adj[MAX];
bool Visited[MAX];

int go(int n) {
    int &ret = DP[n];
    if (ret != 0)
        return ret;

    ret = 1;
    Visited[n] = true;
    for (auto &next: Adj[n]) {
        if (Visited[next])
            continue;

        ret += go(next);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> R >> Q;

    int u, v;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    go(R);
    int q;
    for (int i = 0; i < Q; ++i) {
        cin >> q;
        cout << DP[q] << '\n';
    }
    return 0;
}