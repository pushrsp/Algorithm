#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAX 100001
#define INF 987654321

using namespace std;

vector<int> Adj[MAX];
bool Visited[MAX];
int DP[2][MAX];

void go(int node) {
    DP[0][node] = 0, DP[1][node] = 1;
    Visited[node] = true;

    for (auto &next: Adj[node]) {
        if (Visited[next])
            continue;

        go(next);
        DP[0][node] += DP[1][next];
        DP[1][node] += min(DP[1][next], DP[0][next]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    for (auto &l: lighthouse) {
        Adj[l[0]].push_back(l[1]);
        Adj[l[1]].push_back(l[0]);
    }

    go(1);
    
    return min(DP[0][1], DP[1][1]);
}