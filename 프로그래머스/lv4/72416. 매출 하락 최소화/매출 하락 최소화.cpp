#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define MAX 300001
#define INF 987654321

using namespace std;

vector<int> Adj[MAX];
int DP[MAX][2], Sales[MAX];

void go(int n) {
    DP[n][0] = 0, DP[n][1] = Sales[n];
    if (Adj[n].empty())
        return;

    int temp = INF;
    for (auto &next: Adj[n]) {
        go(next);

        //자식 노드가 아무도 참여하지 않을 때
        if (DP[next][0] < DP[next][1]) {
            DP[n][0] += DP[next][0], DP[n][1] += DP[next][0];
            temp = min(temp, DP[next][1] - DP[next][0]);
        } else {
            DP[n][0] += DP[next][1], DP[n][1] += DP[next][1];
            temp = 0;
        }
    }

    //본인 노드 포함 아무도 안나갈 때 자식 노드 중 제일 최소값만 저장
    DP[n][0] += temp;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for (int i = 0; i < sales.size(); ++i)
        Sales[i + 1] = sales[i];

    for (auto &link: links)
        Adj[link[0]].push_back(link[1]);

    go(1);

    return min(DP[1][0], DP[1][1]);
}