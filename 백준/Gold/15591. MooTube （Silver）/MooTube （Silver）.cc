#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define ll long long

using namespace std;

int N, Q;
vector<vector<pair<int, ll>>> Adj;

int bfs(int s, int k) {
    queue<pair<int, int>> q;
    vector<bool> visited(N + 1, false);

    q.emplace(s, INT32_MAX);
    visited[s] = true;

    int count = 0;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (auto &child: Adj[now.first]) {
            if (visited[child.first])
                continue;
            if (child.second < k)
                continue;

            count++;
            visited[child.first] = true;
            q.emplace(child.first, child.second);
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;
    Adj = vector<vector<pair<int, ll>>>(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int p, q, r;
        cin >> p >> q >> r;

        Adj[p].emplace_back(q, r);
        Adj[q].emplace_back(p, r);
    }

    for (int i = 0; i < Q; ++i) {
        int k, v;
        cin >> k >> v;

        cout << bfs(v, k) << '\n';
    }
    return 0;
}