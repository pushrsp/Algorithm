#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

#define INF 987654321
#define ll long long

using namespace std;

int N, T, InDegree[501], Duration[501], Ret[501];
vector<vector<int>> Adj(501);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> Duration[i];

        while (true) {
            cin >> T;
            if (T == -1)
                break;

            Adj[T].push_back(i);
            InDegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (InDegree[i] == 0)
            q.push(i), Ret[i] = Duration[i];
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int &next: Adj[now]) {
            InDegree[next]--;

            Ret[next] = max(Ret[next], Ret[now] + Duration[next]);
            if (InDegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << Ret[i] << '\n';
    
    return 0;
}