#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;
vector<vector<int>> TREE;
vector<int> INFO;

bool visited[18][18][18];

void DFS(int idx, int sheep, int wolf) {
    answer = max(answer, sheep);

    for (int next: TREE[idx]) {
        if (INFO[next] == 0) {
            if (!visited[next][sheep + 1][wolf]) {
                visited[next][sheep + 1][wolf] = true;
                INFO[next] = -1;
                DFS(next, sheep + 1, wolf);
                INFO[next] = 0;
                visited[next][sheep + 1][wolf] = false;
            }
        } else if (INFO[next] == 1) {
            if (!visited[next][sheep][wolf + 1] && sheep > wolf + 1) {
                visited[next][sheep][wolf + 1] = true;
                INFO[next] = -1;
                DFS(next, sheep, wolf + 1);
                INFO[next] = 1;
                visited[next][sheep][wolf + 1] = false;
            }
        } else {
            if (!visited[next][sheep][wolf]) {
                visited[next][sheep][wolf] = true;
                DFS(next, sheep, wolf);
                visited[next][sheep][wolf] = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    INFO = info;
    TREE = vector<vector<int>>(info.size());

    for (vector<int> &edge: edges) {
        TREE[edge[0]].push_back(edge[1]);
        TREE[edge[1]].push_back(edge[0]);
    }

    INFO[0] = -1;
    visited[0][1][0] = true;
    DFS(0, 1, 0);

    return answer;
}