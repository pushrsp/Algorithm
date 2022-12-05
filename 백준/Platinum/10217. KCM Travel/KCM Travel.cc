#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define INF 987654321
#define ll long long

using namespace std;

struct Node {
    int node, price, dist;
};


int T, N, M, K, DP[101][10001];
vector<pair<int, int>> Dist[101], Price[101];

struct Cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.dist > b.dist;
    }
};

void Refresh() {
    for (int i = 1; i <= N; ++i)
        Dist[i].clear(), Price[i].clear();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            DP[i][j] = INF;
        }
    }
}

void Di(int start, int dest) {
    int answer = INT32_MAX;
    priority_queue<Node, vector<Node>, Cmp> pq;

    pq.push({start, 0, 0});

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.price > M || now.dist > answer)
            continue;
        if (now.node == dest) {
            answer = min(answer, now.dist);
            continue;
        }

        for (int i = 0; i < Dist[now.node].size(); ++i) {
            int next_node = Dist[now.node][i].first;
            int next_dist = Dist[now.node][i].second + now.dist;
            int next_price = Price[now.node][i].second + now.price;

            if (next_price <= M && next_dist < DP[next_node][next_price]) {
                for (int j = next_price + 1; j <= M; j++) {
                    if (DP[next_node][j] <= next_dist)
                        break;

                    DP[next_node][j] = next_dist;
                }
                
                DP[next_node][next_price] = next_dist;
                pq.push({next_node, next_price, next_dist});
            }
        }
    }

    if (answer == INT32_MAX)
        cout << "Poor KCM" << '\n';
    else
        cout << answer << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> M >> K;

        Refresh();
        for (int i = 0; i < K; ++i) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            Dist[a].emplace_back(b, d);
            Price[a].emplace_back(b, c);
        }

        Di(1, N);
    }
    return 0;
}