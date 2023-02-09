#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 10001

using namespace std;

int N, Arr[MAX], DP[MAX][2];
vector<int> Adj[MAX];
bool Visited[MAX];
vector<int> Path;

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

void trace(int n, int p) {
    if (DP[n][1] > DP[n][0] && !Visited[p]) {
        Path.push_back(n);
        Visited[n] = true;
    }

    for (int i = 0; i < Adj[n].size(); ++i) {
        if (Adj[n][i] == p)
            continue;

        trace(Adj[n][i], n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    int v, e;
    for (int i = 0; i < N - 1; ++i) {
        cin >> v >> e;

        Adj[v].push_back(e);
        Adj[e].push_back(v);
    }

    go(1);
    fill(Visited, Visited + MAX, false);
    trace(1, 0);

    sort(Path.begin(), Path.end());

    cout << max(DP[1][0], DP[1][1]) << '\n';
    for (int &p: Path)
        cout << p << ' ';

    return 0;
}