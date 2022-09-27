#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<vector<int>> Nodes;
int Max_Dist[10001];
bool Visited[10001];

int dfs(int node) {
    Visited[node] = true;
    int ret = 1;

    for (auto &child: Nodes[node]) {
        if (Visited[child])
            continue;

        ret += dfs(child);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Nodes = vector<vector<int>>(N + 1);
    for (int m = 0; m < M; ++m) {
        int a, b;
        cin >> a >> b;

        Nodes[b].push_back(a);
    }

    int max_dist = -1;
    for (int i = 1; i <= N; ++i) {
        memset(Visited, false, N + 1);
        int dist = dfs(i);
        max_dist = max(max_dist, dist);
        Max_Dist[i] = dist;
    }

    for (int i = 1; i <= N; ++i) {
        if (Max_Dist[i] == max_dist)
            cout << i << " ";
    }
    return 0;
}