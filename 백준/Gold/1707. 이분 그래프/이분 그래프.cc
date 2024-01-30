#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int K, V, E;
vector<int> G[20001];
int Visited[20001];

void bfs(int start) {
    queue<int> q;

    Visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (auto &next: G[curr]) {
            if (Visited[next] == 0) {
                Visited[next] = Visited[curr] == 1 ? 2 : 1;
                q.push(next);
            }
        }
    }
}

bool is_valid() {
    for (int v = 1; v <= V; ++v) {
        for (auto &next: G[v]) {
            if (Visited[v] == Visited[next])
                return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K;

    while (K--) {
        cin >> V >> E;

        int f, s;
        for (int e = 0; e < E; ++e) {
            cin >> f >> s;

            G[f].push_back(s);
            G[s].push_back(f);
        }

        for (int v = 1; v <= V; ++v) {
            if (Visited[v] == 0)
                bfs(v);
        }

        if (is_valid())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        for (int v = 0; v <= V; ++v)
            G[v].clear();

        ::memset(Visited, false, sizeof(Visited));
    }

    return 0;
}