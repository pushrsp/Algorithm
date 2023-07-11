#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, InDegree[1001];
vector<int> Adj[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int m = 0; m < M; ++m) {
        cin >> a >> b;

        Adj[a].push_back(b);
        InDegree[b]++;
    }

    queue<pair<int, int>> q;
    for (int i = 1; i <= N; ++i) {
        if (InDegree[i] == 0) {
            q.emplace(i, 1);
            InDegree[i] = 1;
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        InDegree[curr.first] = curr.second;

        for (auto &next: Adj[curr.first]) {
            if (--InDegree[next] == 0)
                q.emplace(next, curr.second + 1);
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << InDegree[i] << ' ';

    return 0;
}