#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

vector<vector<int>> Nodes;
int N, Remove, Root;

int dfs(int node) {
    int ret = 0;
    int cnt = 0;

    for (auto &child: Nodes[node]) {
        if (child == Remove)
            continue;
        ret += dfs(child);
        cnt++;
    }

    if (cnt == 0)
        return 1;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Nodes = vector<vector<int>>(N);
    for (int n = 0; n < N; ++n) {
        int node;
        cin >> node;

        if (node == -1) {
            Root = n;
            continue;
        }

        Nodes[node].push_back(n);
    }

    cin >> Remove;
    if (Remove == Root) {
        cout << 0 << '\n';
        return 0;
    }

    cout << dfs(Root) << '\n';
    return 0;
}