#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

#define MAX 501

using namespace std;

int DP[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int maxY = static_cast<int>(triangle.size());

    DP[0][0] = triangle[0][0];
    for (int y = 1; y < maxY; ++y) {
        for (int x = 0; x < triangle[y].size(); ++x) {
            if (x == 0)
                DP[y][x] = triangle[y][x] + DP[y - 1][x];
            else if (x == triangle[y].size() - 1)
                DP[y][x] = triangle[y][x] + DP[y - 1][x - 1];
            else
                DP[y][x] = max(DP[y - 1][x - 1], DP[y - 1][x]) + triangle[y][x];
        }
    }

    int answer = 0;
    for (int x = 0; x < triangle[maxY - 1].size(); ++x)
        answer = max(answer, DP[maxY - 1][x]);

    return answer;
}