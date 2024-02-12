#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

struct Point {
    int u, v;
    ll w;
};

struct Node {
    int n;
    ll w, a;

    bool operator<(const Node &other) const {
        if (w == other.w)
            return a < other.a;

        return w > other.w;
    }
};

int N, M, A[100001], S, T;
vector<pair<int, ll>> G[100001];
pair<ll, ll> D[100001];

void Di() {
    priority_queue<Node> pq;

    D[S].first = 0;
    D[S].second = A[S];
    pq.push({S, 0, A[S]});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (D[curr.n].first < curr.w)
            continue;

        for (auto &next: G[curr.n]) {
            int next_node = next.first;
            ll next_dist = curr.w + next.second;
            ll next_water = curr.a + A[next_node];

            if (D[next_node].first > next_dist) {
                D[next_node].first = next_dist;
                D[next_node].second = next_water;
                pq.push({next_node, next_dist, next_water});
            } else if (D[next_node].first == next_dist) {
                if (next_water > D[next_node].second) {
                    D[next_node].second = next_water;
                    pq.push({next_node, next_dist, next_water});
                }
            }
        }
    }

    if (D[T].first == INT64_MAX)
        cout << -1 << '\n';
    else
        cout << D[T].first << ' ' << D[T].second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int n = 1; n <= N; ++n)
        cin >> A[n];

    cin >> M;

    ll u, v, w;
    for (int m = 0; m < M; ++m) {
        cin >> u >> v >> w;

        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    cin >> S >> T;

    for (int n = 1; n <= N; ++n)
        D[n].first = INT64_MAX;

    Di();

    return 0;
}