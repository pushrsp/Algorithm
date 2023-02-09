#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 10001

using namespace std;

int N, Arr[MAX], DP[MAX][2];
vector<int> Adj[MAX];
bool Visited[MAX];

void go(int n) {
    Visited[n] = true;

    DP[n][1] = Arr[n], DP[n][0] = 0;
    for (auto &next: Adj[n]) {
        if (Visited[next])
            continue;

        go(next);
        DP[n][0] += max(DP[next][0], DP[next][1]);
        DP[n][1] += DP[next][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    int u, v;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    go(1);
    cout << max(DP[1][0], DP[1][1]) << '\n';
    return 0;
}