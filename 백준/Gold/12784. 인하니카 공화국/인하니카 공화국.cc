#include <iostream>
#include <vector>

using namespace std;

struct Bridge
{
    int idx, dynamite;
};

int T, N, M;
vector<vector<Bridge>> nodes;
vector<int> visited;

int dfs(int node, int parent) {
    if (visited[node] == 0)
    {
        int ret = INT32_MAX, sum = 0;
        for (Bridge& child : nodes[node])
        {
            if (child.idx == parent)
            {
                ret = child.dynamite;
                continue;
            }

            if (nodes[child.idx].size() == 1)
                sum += child.dynamite;
            else
                sum += dfs(child.idx, node);
        }

        ret = min(ret, sum);
        visited[node] = ret;
    }

    return visited[node];
}

int main() {
    cin >> T;

    while (T--) {
        cin >> N >> M;

        visited = vector<int>(N + 1);
        nodes = vector<vector<Bridge>>(N + 1);

        for (int m = 0; m < M; ++m) {
            int from, to, dynamite;
            cin >> from >> to >> dynamite;

            nodes[from].push_back({ to, dynamite });
            nodes[to].push_back({ from, dynamite });
        }

        cout << dfs(1, 0) << endl;
    }

    return 0;
}