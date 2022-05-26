#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int *dist;
int FROM, TO;
vector<vector<int>> graph;

int BFS() {
    queue<int> q;
    q.push(FROM - 1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == TO - 1)
            return dist[v];

        for (int a: graph[v]) {
            if (!dist[a]) {
                dist[a] = dist[v] + 1;
                q.push(a);
            }
        }
    }

    return -1;
}

int main() {
    int n, k;
    cin >> n >> FROM >> TO >> k;

    dist = new int[n]{0,};

    for (int i = 0; i < n; ++i) {
        vector<int> a;
        graph.push_back(a);
    }

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;

        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    cout << BFS() << endl;

    return 0;
}