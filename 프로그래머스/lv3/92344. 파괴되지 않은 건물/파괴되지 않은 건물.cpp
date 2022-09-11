#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int visited[1010][1010];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    for (vector<int> &s: skill) {
        int type = s[0], degree = s[5];
        int y1 = s[1], x1 = s[2], y2 = s[3], x2 = s[4];
        degree = type == 1 ? degree * -1 : degree;

        visited[y1][x1] += degree;
        visited[y2 + 1][x2 + 1] += degree;
        visited[y1][x2 + 1] -= degree;
        visited[y2 + 1][x1] -= degree;
    }


    for (int i = 0; i <= board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            visited[i][j + 1] += visited[i][j];
        }
    }

    for (int j = 0; j <= board[0].size(); ++j) {
        for (int i = 0; i < board.size(); ++i) {
            visited[i + 1][j] += visited[i][j];
        }
    }

    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[0].size(); ++x) {
            if (board[y][x] + visited[y][x] > 0)
                answer++;
        }
    }

    return answer;
}