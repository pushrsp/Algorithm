#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool *visited;
vector<vector<int>> adj;

int bfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int count = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int a: adj[v]) {
            if (!visited[a]) {
                q.push(a);
                visited[a] = true;
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, e;
    cin >> n >> e;

    visited = new bool[n]{false,};
    for (int i = 0; i < n; ++i) {
        vector<int> k;
        adj.push_back(k);
    }

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n - 1; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    cout << bfs(0);

    return 0;
}