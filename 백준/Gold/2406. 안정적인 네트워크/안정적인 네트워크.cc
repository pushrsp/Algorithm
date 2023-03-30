#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 1001

using namespace std;

struct Edge {
    int dist, n1, n2;
};

int N, M;
int Parent[MAX], Dist[MAX][MAX];
vector<Edge> Edges;

int GetParent(int i) {
    if (i == Parent[i])
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a > b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

bool cmp_edge(const Edge &a, const Edge &b) {
    return a.dist < b.dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        Parent[i] = i;

    int x, y;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;

        if (GetParent(x) != GetParent(y))
            Union(x, y);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            cin >> Dist[i][j];
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j)
            Edges.push_back({Dist[i][j], i, j});
    }

    sort(Edges.begin(), Edges.end(), cmp_edge);

    int ret = 0;
    vector<pair<int, int>> candidates;

    for (Edge &edge: Edges) {
        if (GetParent(edge.n1) != GetParent(edge.n2)) {
            Union(edge.n1, edge.n2);
            candidates.emplace_back(edge.n1, edge.n2);
            ret += edge.dist;
        }
    }

    if (candidates.empty()) {
        cout << 0 << ' ' << 0 << '\n';
    } else {
        cout << ret << ' ' << candidates.size() << '\n';
        for (auto &cand: candidates)
            cout << cand.second << ' ' << cand.first << '\n';
    }
    return 0;
}