#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Point {
    int n, k, t;

    bool operator<(const Point &other) const {
        return t > other.t;
    }
};

int N, M, K, Dist[501][2];
vector<int> Adj[501];
map<int, vector<vector<int>>> Info;

int Di() {
    priority_queue<Point> pq;
    for (auto &info: Info[1])
        pq.push({info[0], K, info[1]});

    Dist[1][0] = 0, Dist[1][1] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.n == N)
            return curr.t;

        for (auto &next: Info[curr.n]) {
            int next_gap = 0;
            while (next_gap < curr.t)
                next_gap += next[2];

            int next_time = curr.t + next_gap - curr.t + next[1];
            int next_node = next[0];

            if (Dist[next_node][0] > next_time) {
                Dist[next_node][0] = next_time;
                pq.push({next_node, curr.k, next_time});
            }

            if (curr.k > 0 && Dist[next_node][1] > curr.t + next[1]) {
                Dist[next_node][1] = curr.t + next[1];
                pq.push({next[0], curr.k - 1, curr.t + next[1]});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    int s, e, t, g;
    for (int m = 0; m < M; ++m) {
        cin >> s >> e >> t >> g;

        Adj[s].push_back(e);
        Info[s].push_back({e, t, g});
    }

    fill(&Dist[0][0], &Dist[0][0] + 501 * 2, INF);
    cout << Di() << '\n';

    return 0;
}