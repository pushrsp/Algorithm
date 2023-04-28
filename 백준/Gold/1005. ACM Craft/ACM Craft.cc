#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1001

using namespace std;

int T, N, K, W, Arr[MAX], InDegree[MAX], Result[MAX];
vector<int> Adj[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        for (int i = 1; i <= N; ++i) {
            Adj[i].clear();
            Arr[i] = 0, InDegree[i] = 0, Result[i] = 0;
        }

        cin >> N >> K;
        for (int i = 1; i <= N; ++i) {
            cin >> Arr[i];
            Result[i] = Arr[i];
        }

        int x, y;
        for (int i = 0; i < K; ++i) {
            cin >> x >> y;
            Adj[x].push_back(y);
            InDegree[y]++;
        }

        cin >> W;

        if (InDegree[W] == 0) {
            cout << Result[W] << '\n';
            continue;
        }

        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (InDegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (int &next: Adj[curr]) {
                Result[next] = max(Result[next], Result[curr] + Arr[next]);
                if (--InDegree[next] == 0)
                    q.emplace(next);
            }
        }

        cout << Result[W] << '\n';
    }
    
    return 0;
}