#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAX 18

using namespace std;

int Answer = 0;
bool Visited[MAX][(1 << (MAX - 1)) + 1];
vector<int> Info, Adj[MAX];

void go(int wolf, int sheep, int node, int visited) {
    Answer = max(Answer, sheep);

    for (auto &next: Adj[node]) {
        int next_wolf = wolf, next_sheep = sheep;
        if (!(visited & (1 << next))) {
            if (Info[next])
                next_wolf += 1;
            else
                next_sheep += 1;
        }

        if (next_wolf >= next_sheep)
            continue;
        if (Visited[next][visited | (1 << next)])
            continue;

        Visited[next][visited | (1 << next)] = true;
        go(next_wolf, next_sheep, next, visited | (1 << next));
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    Info = info;

    for (auto &edge: edges) {
        Adj[edge[0]].push_back(edge[1]);
        Adj[edge[1]].push_back(edge[0]);
    }

    if (Info[0] == 0)
        Answer = 1;
    
    go(0, 0, 0, 0);

    return Answer;
}