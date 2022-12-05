#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 987654321
#define ll long long

using namespace std;

int N, M, Dist[1001], Visited[1001];
vector<pair<int, int>> Adj[1001];

void Di(int start, int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    Dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.first > Dist[now.second])
            continue;

        for (auto &i: Adj[now.second]) {
            int next_node = i.first, next_cost = i.second;
            if (now.first + next_cost < Dist[next_node]) {
                Visited[next_node] = now.second;
                Dist[next_node] = now.first + next_cost;
                pq.emplace(Dist[next_node], next_node);
            }
        }
    }

    vector<int> temp;
    int now = dest;

    while (now) {
        temp.push_back(now);
        now = Visited[now];
    }

    cout << Dist[dest] << '\n';
    cout << temp.size() << '\n';

    for (int i = temp.size() - 1; i >= 0; --i)
        cout << temp[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;

    fill(Dist, Dist + 1001, INF);

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        Adj[a].emplace_back(b, c);
    }

    int start, dest;
    cin >> start >> dest;

    Di(start, dest);
    return 0;
}