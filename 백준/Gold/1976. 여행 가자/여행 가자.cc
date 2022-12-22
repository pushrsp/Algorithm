#include <iostream>
#include <vector>
#include <queue>

#define MAX 201
#define INF 987654321

using namespace std;

int N, M, Dist[MAX];
vector<vector<int>> Adj;

void Di(int node) {
    priority_queue<pair<int, int>> pq;

    Dist[node] = 0;
    pq.emplace(0, node);

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (int next = 1; next <= N; ++next) {
            int is_connected = Adj[cur_node][next];
            if(is_connected == 0)
                continue;

            if(Dist[next] > cur_cost + is_connected) {
                Dist[next] = cur_cost + is_connected;
                pq.emplace(-Dist[next], next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    fill(Dist, Dist + 201, INF);

    cin >> N;
    cin >> M;

    Adj = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> Adj[i][j];
        }
    }

    int prev, cur;
    cin >> prev;

    Di(prev);

    bool flag = true;
    for (int i = 0; i < M - 1; ++i) {
        cin >> cur;
        if(Dist[cur] == INF) {
            flag = false;
            continue;
        }

        prev = cur;
        fill(Dist, Dist + 201, INF);
        Di(prev);
    }

    if(flag)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}