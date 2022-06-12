#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> answer;
int N;

void BFS(int depth) {
    vector<bool> visited(N + 1, false);
    vector<int> dist(N + 1, 0);
    queue<int> q;
    q.push(depth);
    visited[depth] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto i: adj[v]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                dist[i] = dist[v] + 1;
            }
        }
    }

    int high = dist[1];
    for (int i = 2; i <= N; ++i) {
        if (high < dist[i])
            high = dist[i];
    }

    answer[depth] = high;
}

int main() {
    cin >> N;
    adj = vector<vector<int>>(N + 1);
    answer = vector<int>(N + 1);

    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == -1 && m == -1)
            break;

        adj[n].push_back(m);
        adj[m].push_back(n);
    }

    for (int i = 1; i <= N; ++i) {
        BFS(i);
    }

    int low = answer[1];
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (answer[i] < low)
            low = answer[i];
    }

    for (int i = 1; i <= N; ++i) {
        if (answer[i] == low)
            cnt++;
    }

    cout << low << " " << cnt << endl;
    for (int i = 1; i <= N; ++i) {
        if (answer[i] == low)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}