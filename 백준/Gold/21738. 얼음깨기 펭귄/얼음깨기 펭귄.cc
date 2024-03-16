#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define INF 987654321

using namespace std;

int N, S, P, Dist[400000];
vector<int> Adj[400000];

int di() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    Dist[P] = 0;
    pq.emplace(0, P);

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for (auto &next: Adj[curr]) {
            if (Dist[next] > dist + 1) {
                Dist[next] = dist + 1;
                pq.emplace(Dist[next], next);
            }
        }
    }

    sort(Dist + 1, Dist + 1 + S);

    return N - Dist[1] - Dist[2] - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S >> P;

    int a, b;
    for (int n = 0; n < N - 1; ++n) {
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    fill(Dist, Dist + 400000, INF);

    cout << di() << '\n';

    return 0;
}