#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Point {
    int x, y, z;
};

int N, M, Dist[1001], Prev[1001];
vector<pair<int, int>> Adj[1001];

void Di1(int start) {
    priority_queue<pair<int, int>> pq;

    Dist[start] = 0;
    Prev[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int curr_dist = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        for (auto &next: Adj[curr_node]) {
            int next_node = next.first;
            int next_dist = next.second + curr_dist;

            if (Dist[next_node] > next_dist) {
                Dist[next_node] = next_dist;
                pq.emplace(-next_dist, next_node);
                Prev[next_node] = curr_node;
            }
        }
    }
}

int Di2() {
    vector<int> dist(1001, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        int curr_dist = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        for (auto &next: Adj[curr_node]) {
            if (next.second == -1)
                continue;

            int next_node = next.first;
            int next_dist = curr_dist + next.second;

            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.emplace(-next_dist, next_node);
            }
        }
    }

    return dist[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int x, y, z;
    for (int m = 0; m < M; ++m) {
        cin >> x >> y >> z;

        Adj[x].emplace_back(y, z);
        Adj[y].emplace_back(x, z);
    }

    fill(Dist, Dist + 1001, INF);
    Di1(1);

    int curr = N, ret = 0;
    while (curr != 1) {
        int prev = Prev[curr];
        for (auto &node: Adj[prev]) {
            if (node.first == curr && Dist[curr] - node.second == Dist[prev]) {
                int temp = node.second;

                node.second = -1;
                ret = max(ret, Di2());
                node.second = temp;
                curr = prev;
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}