#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

void BFS(int node) {
    queue<int> q;

    q.push(node);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (visited[now])
            continue;

        visited[now] = true;
        for (int i: adj[now]) {
            if (!visited[i])
                q.push(i);
        }
    }
}

int main() {
    cin >> N >> M;

    adj = vector<vector<int>>(N);
    visited = vector<bool>(N, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int cnt = 0;
    for (int y = 0; y < N; ++y) {
        if (!visited[y]) {
            cnt++;
            BFS(y);
        }
    }

    cout << cnt << endl;

    return 0;
}