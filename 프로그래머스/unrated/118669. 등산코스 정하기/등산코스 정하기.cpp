#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> BOARD;
vector<bool> summits_visited;
vector<int> dist;

vector<int> BFS(vector<int> &gates, vector<int> &summits) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int gate: gates) {
        pq.push({0, gate});
        dist[gate] = 0;
    }


    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (summits_visited[now.second]) {
            dist[now.second] = min(dist[now.second], now.first);
            continue;
        }

        for (auto &p: BOARD[now.second]) {
            int next_weight = max(now.first, p.first);

            if (next_weight < dist[p.second]) {
                dist[p.second] = next_weight;
                pq.push({next_weight, p.second});
            }
        }
    }

    vector<int> answer = {0, INT32_MAX};
    for (int summit: summits) {
        if (dist[summit] < answer[1]) {
            answer[0] = summit;
            answer[1] = dist[summit];
        }
    }

    return answer;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    BOARD = vector<vector<pair<int, int>>>(n + 1);
    for (auto &p: paths) {
        BOARD[p[0]].push_back({p[2], p[1],});
        BOARD[p[1]].push_back({p[2], p[0],});
    }

    sort(summits.begin(), summits.end());
    summits_visited = vector<bool>(n + 1, false);
    dist = vector<int>(n + 1, INT32_MAX);

    for (int summit: summits)
        summits_visited[summit] = true;

    answer = BFS(gates, summits);
    
    return answer;
}