#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T;
vector<vector<int>> Nodes;
vector<bool> Visited;

int bfs(int node) {
    queue<int> q;

    q.push(node);
    Visited[node] = true;

    int cnt = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int n: Nodes[now]) {
            if (Visited[n])
                continue;

            Visited[n] = true;
            cnt++;
            q.push(n);
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        Nodes = vector<vector<int>>(n + 1);
        Visited = vector<bool>(n + 1, false);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            Nodes[a].push_back(b);
            Nodes[b].push_back(a);
        }

        if (n - m <= 0) {
            cout << "graph" << '\n';
            continue;
        }

        int nodes = bfs(n);
        if (nodes == n)
            cout << "tree" << '\n';
        else
            cout << "graph" << '\n';
    }
    return 0;
}