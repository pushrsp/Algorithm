#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define ll long long
#define MAX 501
#define INF 987654321

using namespace std;

struct Node {
    ll from, to, cost;
};

ll T, N, M, W, Dist[MAX];
vector<Node> Nodes;

bool Bell() {
    Dist[1] = 0;

    for (int i = 1; i <= N - 1; ++i) {
        for (Node &node: Nodes) {
            ll from = node.from, to = node.to, cost = node.cost;

            if (Dist[from] == INF)
                continue;
            if (Dist[to] > Dist[from] + cost)
                Dist[to] = Dist[from] + cost;
        }
    }

    for (Node &node: Nodes) {
        ll from = node.from, to = node.to, cost = node.cost;

        if (Dist[from] == INF)
            continue;
        if (Dist[to] > Dist[from] + cost)
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    int s, e, t;
    while (T--) {
        cin >> N >> M >> W;

        for (int i = 0; i < M; ++i) {
            cin >> s >> e >> t;

            Nodes.push_back({s, e, t});
            Nodes.push_back({e, s, t});
        }

        for (int i = 0; i < W; ++i) {
            cin >> s >> e >> t;

            Nodes.push_back({s, e, -t});
        }

        fill(Dist, Dist + MAX, INT32_MAX);

        if (Bell())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        Nodes.clear();
    }
    return 0;
}