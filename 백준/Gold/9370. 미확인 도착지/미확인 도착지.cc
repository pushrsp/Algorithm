#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int T, DistS[2001], DistG[2001], DistH[2001];
vector<vector<pair<int, int>>> Adj;

void Fill(int n) {
    for (int i = 0; i <= n; ++i)
        DistS[i] = INF, DistG[i] = INF, DistH[i] = INF;
}

void Di(int start, int dist[2001]) {
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int d = -pq.top().first, cur = pq.top().second;
        pq.pop();

        for(auto& child: Adj[cur]) {
            int next = child.first, cost = child.second;

            if(dist[next] > d + cost) {
                dist[next] = d + cost;
                pq.emplace(-dist[next], next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> T;
    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;

        Fill(n);
        Adj = vector<vector<pair<int, int>>>(n + 1);

        int s, g, h;
        cin >> s >> g >> h;

        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;

            Adj[a].emplace_back(b, d);
            Adj[b].emplace_back(a, d);
        }

        Di(s, DistS), Di(g, DistG), Di(h, DistH);
        vector<int> candidates(t);
        for (int i = 0; i < t; ++i)
            cin >> candidates[i];

        sort(candidates.begin(), candidates.end());

        for(int& dest: candidates) {
            // s -> g -> h -> dest
            if(DistS[dest] == DistS[g] + DistG[h] + DistH[dest]) {
                cout << dest << '\n';
                continue;
            }

            // s -> h -> g -> dest
            if(DistS[dest] == DistS[h] + DistH[g] + DistG[dest]) {
                cout << dest << '\n';
                continue;
            }
        }
    }
    return 0;
}