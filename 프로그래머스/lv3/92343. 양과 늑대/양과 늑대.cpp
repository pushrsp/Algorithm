#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int answer = 0;
vector<vector<int>> Tree;
vector<int> Info;
vector<bool> Visited(131073, false);

void dfs(int sheep, int wolf, int idx, int visited) {
    if (Info[idx])
        wolf++;
    else
        sheep++;

    answer = max(answer, sheep);
    if (wolf >= sheep)
        return;

    for (int i = 0; i < Info.size(); ++i) {
        if (!(visited & (1 << i)))
            continue;

        for (auto &child: Tree[i]) {
            int nextVisited = visited | (1 << child);

            if (Visited[nextVisited])
                continue;

            Visited[nextVisited] = true;
            dfs(sheep, wolf, child, nextVisited);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    Info = info;
    Tree = vector<vector<int>>(info.size());
    for (auto &edge: edges) {
        Tree[edge[0]].push_back(edge[1]);
        Tree[edge[1]].push_back(edge[0]);
    }

    Visited[1 << 0] = true;
    dfs(0, 0, 0, (1 << 0));

    return answer;
}