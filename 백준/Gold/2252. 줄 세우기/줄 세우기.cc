#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> Adj[32001];
int InDegree[32001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        Adj[a].push_back(b);
        InDegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (InDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        cout << now << ' ';
        for (int &next: Adj[now]) {
            InDegree[next]--;

            if (InDegree[next] == 0)
                q.push(next);
        }
    }
    return 0;
}