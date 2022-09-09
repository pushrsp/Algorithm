#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graph;

int main() {
    cin >> N >> M;

    graph = vector<vector<int>>(102);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> dist(102, vector<int>(102, -1));
    for (int i = 1; i <= N; ++i) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int child: graph[now]) {
                if (dist[i][child] != -1)
                    continue;

                dist[i][child] = dist[i][now] + 1;
                q.push(child);
            }
        }
    }


    pair<int, pair<int, int>> answer = {INT32_MAX, {INT32_MAX, INT32_MAX}};
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int sum = 0;

            for (int k = 1; k <= N; ++k)
                sum += 2 * min(dist[i][k], dist[j][k]);

            answer = min(answer, {sum, {i, j}});
        }
    }

    cout << answer.second.first << " " << answer.second.second << " " << answer.first << endl;
    return 0;
}