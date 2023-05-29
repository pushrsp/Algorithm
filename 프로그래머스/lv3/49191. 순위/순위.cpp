#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 101

using namespace std;

bool Adj[MAX][MAX];

int solution(int n, vector<vector<int>> results) {
    for (auto &result: results)
        Adj[result[0]][result[1]] = true;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (Adj[i][k] && Adj[k][j])
                    Adj[i][j] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                continue;
            if (Adj[i][j] || Adj[j][i])
                count++;
        }

        if (count == n - 1)
            answer++;
    }

    return answer;
}