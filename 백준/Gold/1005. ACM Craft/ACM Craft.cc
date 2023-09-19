#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

int T, N, K, W, Duration[1001], InDegree[1001], Visited[1001];
vector<int> Adj[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N >> K;

        for (int n = 1; n <= N; ++n) {
            Adj[n].clear();
            InDegree[n] = 0, Visited[n] = 0;

            cin >> Duration[n];
            Visited[n] = Duration[n];
        }

        int x, y;
        for (int k = 0; k < K; ++k) {
            cin >> x >> y;
            Adj[x].push_back(y);
            InDegree[y]++;
        }

        cin >> W;

        if (InDegree[W] == 0) {
            cout << Visited[W] << '\n';
            continue;
        }

        queue<int> q;
        for (int n = 1; n <= N; ++n) {
            if (InDegree[n] == 0)
                q.push(n);
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (auto &next: Adj[curr]) {
                Visited[next] = max(Visited[next], Visited[curr] + Duration[next]);
                if (--InDegree[next] == 0)
                    q.push(next);
            }
        }

        cout << Visited[W] << '\n';
    }
    return 0;
}