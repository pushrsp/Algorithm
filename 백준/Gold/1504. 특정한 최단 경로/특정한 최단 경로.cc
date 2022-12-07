#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

#define INF 987654321
#define ll long long

using namespace std;

int N, E, Dist[801];
vector<vector<pair<int, int>>> Adj;

void Fill() {
    for (int i = 0; i <= N; ++i)
        Dist[i] = INF;
}

void Di(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    Dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (auto &next: Adj[now]) {
            int next_node = next.first, next_cost = cost + next.second;
            if (Dist[next_node] > next_cost) {
                Dist[next_node] = next_cost;
                pq.emplace(next_cost, next_node);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> E;
    Adj = vector<vector<pair<int, int>>>(N + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        Adj[a].emplace_back(b, c);
        Adj[b].emplace_back(a, c);
    }

    int a, b;
    cin >> a >> b;

    Fill();
    Di(1);
    int sToA = Dist[a], sToB = Dist[b];

    Fill();
    Di(a);
    int aToB = Dist[b], aToN = Dist[N];

    Fill();
    Di(b);
    int bToN = Dist[N];

    int answer = min(INF, sToA + aToB + bToN);
    answer = min(answer, sToB + aToB + aToN);

    if (answer == INF || aToN == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}