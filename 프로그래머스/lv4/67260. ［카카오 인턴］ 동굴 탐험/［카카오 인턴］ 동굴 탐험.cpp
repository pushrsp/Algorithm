#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define MAX 200001

using namespace std;

vector<vector<int>> Adj;
int InDegree[MAX], N;
bool Visited[MAX];
vector<int> Parent[MAX];

void go(int node) {
    Visited[node] = true;

    for (auto &child: Adj[node]) {
        if (Visited[child])
            continue;

        Parent[node].push_back(child);
        go(child);
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    N = n;
    Adj = vector<vector<int>>(n);

    for (auto &p: path) {
        Adj[p[0]].push_back(p[1]);
        Adj[p[1]].push_back(p[0]);
    }

    go(0);

    for (auto &o: order) {
        if (o[1] == 0)
            return false;
        
        Parent[o[0]].push_back(o[1]);
    }

    fill(Visited, Visited + MAX, false);
    queue<int> q;

    Visited[0] = true;
    q.push(0);

    for (int i = 0; i < N; ++i) {
        for (auto &node: Parent[i])
            InDegree[node]++;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &next: Parent[cur]) {
            if (Visited[next])
                continue;

            if (--InDegree[next] == 0) {
                q.push(next);
                Visited[next] = true;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!Visited[i])
            return false;
    }

    return true;
}