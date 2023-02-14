#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

#define MAX 51
#define INF 987654321

using namespace std;

vector<pair<int, int>> Adj[MAX];
int Dist[MAX];

void Di(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    Dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        for (auto &next: Adj[cur_node]) {
            int next_node = next.first;
            int next_dist = cur_dist + next.second;

            if (Dist[next_node] > next_dist) {
                Dist[next_node] = next_dist;
                pq.emplace(next_dist, next_node);
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    for (auto &r: road) {
        Adj[r[0]].emplace_back(r[1], r[2]);
        Adj[r[1]].emplace_back(r[0], r[2]);
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        fill(Dist, Dist + MAX, INF);
        Di(i);

        if (Dist[1] <= K)
            answer += 1;
    }

    return answer;
}