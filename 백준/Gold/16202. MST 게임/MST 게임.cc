#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

struct Edge {
    int n1, n2, dist;
    bool alive;
};

int N, M, K, Parent[MAX];
vector<Edge> Edges;

bool cmp_edge(const Edge &a, const Edge &b) {
    return a.dist < b.dist;
}

int GetParent(int i) {
    if (i == Parent[i])
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);

    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    int x, y;
    for (int m = 1; m <= M; ++m) {
        cin >> x >> y;
        Edges.push_back({x, y, m, true});
    }

    ::sort(Edges.begin(), Edges.end(), cmp_edge);

    int remove_index = 0;
    while (K--) {
        for (int i = 0; i <= N; ++i)
            Parent[i] = i;

        int ret = 0;
        for (auto &edge: Edges) {
            if (!edge.alive)
                continue;

            if (GetParent(edge.n1) != GetParent(edge.n2)) {
                ret += edge.dist;
                Union(edge.n1, edge.n2);
            }
        }

        bool connected = true;
        int cmp = GetParent(1);
        for (int n = 2; n <= N; n++) {
            if (cmp != GetParent(n)) {
                connected = false;
                break;
            }
        }

        if (connected)
            cout << ret << ' ';
        else
            cout << 0 << ' ';

        Edges[remove_index].alive = false;
        remove_index++;
    }
    
    return 0;
}