#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001

using namespace std;

int N, DP[MAX][2];
vector<int> Tree[MAX];
bool Visited[MAX];

void go(int curr) {
    Visited[curr] = true;
    DP[curr][1] = 1;

    for (int &child: Tree[curr]) {
        if (Visited[child])
            continue;

        go(child);

        DP[curr][0] += DP[child][1];
        DP[curr][1] += min(DP[child][0], DP[child][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int u, v;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v;

        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }

    go(1);

    cout << min(DP[1][1], DP[1][0]) << '\n';
    return 0;
}