#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 30000000
int Dist[300][300];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                Dist[i][j] = 0;
            else
                Dist[i][j] = MAX;
        }
    }

    for (auto &fare: fares) {
        int n1 = fare[0] - 1, n2 = fare[1] - 1, weight = fare[2];

        Dist[n1][n2] = weight;
        Dist[n2][n1] = weight;
    }

    //들리는 노드
    for (int k = 0; k < n; ++k) {
        //출발 노드
        for (int i = 0; i < n; ++i) {
            //도착 노드
            for (int j = 0; j < n; ++j) {
                //(출발 노드 -> 들리는 노드) + (들리는 노드 -> 도착 노드) < (출발 노드 -> 도착 노드)
                if (Dist[i][k] + Dist[k][j] < Dist[i][j])
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
            }
        }
    }

    s--;
    a--;
    b--;

    int answer = INT32_MAX;
    for (int k = 0; k < n; ++k)
        answer = min(answer, Dist[s][k] + Dist[k][a] + Dist[k][b]);

    return answer;
}