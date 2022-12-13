#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxDepth = 17;

int N, M;
int Parent[50001][17];
int Depth[50001];
vector<vector<int>> Adj;

void go(int cur) {
    for(int& next: Adj[cur]) {
        if(Depth[next] == -1) {
            Parent[next][0] = cur;
            Depth[next] = Depth[cur] + 1;
            go(next);
        }
    }
}

void Connection() {
    for (int k = 1; k < MaxDepth; ++k) {
        for (int cur = 1; cur <= N; ++cur) {
            Parent[cur][k] = Parent[Parent[cur][k - 1]][k - 1];
        }
    }
}

int LCA(int u, int v) {
    if(Depth[u] < Depth[v])
        swap(u,v);

    int diff = Depth[u] - Depth[v];
    for (int i = 0; diff != 0; ++i) {
        if(diff % 2 == 1)
            u = Parent[u][i];

        diff /= 2;
    }

    if(u != v) {
        for (int i = MaxDepth - 1; i >= 0; --i) {
            if(Parent[u][i] != -1 && Parent[u][i] != Parent[v][i])
                u = Parent[u][i], v = Parent[v][i];
        }

        u = Parent[u][0];
    }

    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ::memset(Parent, -1, sizeof(Parent)), ::memset(Depth, -1, sizeof(Depth));

    cin >> N;

    Adj = vector<vector<int>>(N + 1);

    Depth[1] = 0;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;

        Adj[a].push_back(b), Adj[b].push_back(a);
    }

    go(1);
    Connection();

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;

        cout << LCA(n1, n2) << '\n';
    }
    return 0;
}