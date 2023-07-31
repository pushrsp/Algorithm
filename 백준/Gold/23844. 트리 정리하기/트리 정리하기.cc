#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 10001

using namespace std;

int N, K, Parent[MAX], Depth[MAX], C1[MAX], C2[MAX];
vector<int> Tree[10001];
int max_depth;

void go(int curr, int prev, int depth) {
    Depth[curr] = depth;
    Parent[curr] = prev;
    C1[curr] = 1;
    C2[curr] = 1;
    max_depth = max(max_depth, depth);

    if (Tree[curr].empty())
        return;

    for (auto &next: Tree[curr]) {
        if (next == prev)
            continue;

        go(next, curr, depth + 1);
        C1[curr] += C1[next];
    }

    C2[curr] = C1[curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    int a, b;
    for (int i = 0; i < N - 1; ++i) {
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    go(1, 0, 0);

    vector<vector<int>> dep(max_depth + 1, vector<int>());
    for (int i = 1; i <= N; ++i)
        dep[Depth[i]].push_back(i);

    int ret = 0;
    for (int i = max_depth; i >= 1; --i) {
        int len = static_cast<int>(dep[i].size());

        priority_queue<pair<int, int>> pq;
        for (int j = 0; j < len; ++j)
            pq.emplace(-C2[dep[i][j]], dep[i][j]);

        for (int j = 1; j <= len - K; ++j) {
            int cnt = -pq.top().first;
            int node = pq.top().second;
            pq.pop();

            ret += cnt;
            C2[Parent[node]] -= C1[node];
        }
    }

    cout << N - ret << '\n';

    return 0;
}