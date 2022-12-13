#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define ll long long
#define MAX 20

using namespace std;

int N, M;
vector<int> Adj[30021];
int Depth[30021], Parent[30021][MAX];
bool Visited[30021];

void go(int cur, int depth, int prev) {
    Visited[cur] = true;
    Depth[cur] = depth;
    Parent[cur][0] = prev;

    for(int& node: Adj[cur]) {
        if(!Visited[node])
            go(node, depth + 1, cur);
    }
}

void Connection() {
    for (int k = 1; k < MAX; ++k) {
        for (int cur = 1; cur <= N; ++cur) {
            Parent[cur][k] = Parent[Parent[cur][k-1]][k-1];
        }
    }
}

int LCA(int u, int v) {
    if(Depth[u] > Depth[v])
        swap(u, v);

    for (int i = MAX - 1; i >= 0; --i) {
        int diff = Depth[v] - Depth[u];
        if(diff >= (1 << i))
            v = Parent[v][i];
    }

    if(u != v) {
        for (int i = MAX - 1; i >= 0; --i) {
            if(Parent[u][i] != Parent[v][i])
                u = Parent[u][i], v = Parent[v][i];
        }

        u = Parent[u][0];
    }

    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

//    ::memset(Depth, -1, sizeof(Depth));
//    ::memset(Parent, -1, sizeof(Parent));

    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;

        Adj[a].push_back(b), Adj[b].push_back(a);
    }

    Depth[1] = 0;
    go(1, 0, 1);
    Connection();

    cin >> M;

    ll ret = 0;
    int prev, city;
    for (int i = 0; i < M; ++i) {
        cin >> city;

        if(i > 0)
            ret += Depth[prev] + Depth[city] - 2 * Depth[LCA(city, prev)];

        prev = city;
    }

    cout << ret << '\n';
    return 0;
}