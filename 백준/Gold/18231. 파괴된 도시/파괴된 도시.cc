#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define INF 1e9

using namespace std;

int N, M, K;
vector<int> G[2001];
bool Destroyed[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int u, v;
    for (int m = 0; m < M; ++m) {
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    cin >> K;
    for (int k = 0, n; k < K; ++k) {
        cin >> n;
        Destroyed[n] = true;
    }

    set<int> ans;
    vector<int> nodes;
    for (int n = 1; n <= N; ++n) {
        if (!Destroyed[n])
            continue;

        bool success = true;
        for (auto &next: G[n]) {
            if (!Destroyed[next]) {
                success = false;
                break;
            }
        }

        if (success) {
            nodes.push_back(n);
            ans.insert(n);
            for (auto &next: G[n])
                ans.insert(next);
        }
    }

    if (ans.empty() || ans.size() != K) {
        cout << -1 << '\n';
    } else {
        cout << nodes.size() << '\n';
        for (auto &a: nodes)
            cout << a << ' ';
    }

    return 0;
}