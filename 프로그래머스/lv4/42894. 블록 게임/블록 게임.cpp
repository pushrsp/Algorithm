#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

#define ll long long

using namespace std;

const int BLOCKS[5][3][3] = {
        {
                {1, 0, 0},
                {1, 1, 1},
                {0, 0, 0},
        },
        {
                {0, 1, 0},
                {0, 1, 0},
                {1, 1, 0},
        },
        {
                {1, 0, 0},
                {1, 0, 0},
                {1, 1, 0},
        },
        {
                {0, 0, 1},
                {1, 1, 1},
                {0, 0, 0},
        },
        {
                {0, 1, 0},
                {1, 1, 1},
                {0, 0, 0},
        },
};
const int BLOCKS_COUNT[5][2][2] = {
        {{0, 1}, {0, 2}},
        {{0, 0}, {1, 0}},
        {{0, 1}, {1, 1}},
        {{0, 0}, {0, 1}},
        {{0, 0}, {0, 2}},
};
int MAX_Y, MAX_X, visited[51][51], Answer = 0;
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

bool bfs(int n, int nowY, int nowX, vector<vector<int>> &board) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> vec, temp;
    int min_y = nowY, min_x = nowX;

    vec.emplace_back(nowY, nowX);
    visited[nowY][nowX] = 1;
    q.push({nowY, nowX});

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.first + deltaY[i], nextX = now.second + deltaX[i];

            if (nextY < 0 || nextY >= MAX_Y)
                continue;
            if (nextX < 0 || nextX >= MAX_X)
                continue;
            if (board[nextY][nextX] != n)
                continue;
            if (visited[nextY][nextX])
                continue;

            visited[nextY][nextX] = 1;
            vec.emplace_back(nextY, nextX);
            min_y = min(min_y, nextY), min_x = min(min_x, nextX);
            q.push({nextY, nextX});
        }
    }

    for (auto &pos: vec)
        temp.emplace_back(pos.first - min_y, pos.second - min_x);

    int index = -1;
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (auto &pos: temp) {
            if (BLOCKS[i][pos.first][pos.second] == 0)
                flag = false;
        }

        if (flag) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    vector<vector<int>> c_board(board);
    int y1 = -1, x1 = min_x + BLOCKS_COUNT[index][0][1];
    while (true) {
        int y = y1 + deltaY[2], x = x1 + deltaX[2];

        if (y >= MAX_Y)
            break;
        if (c_board[y][x] != 0)
            break;

        y1 = y, x1 = x;
    }

    if (y1 == -1)
        return false;

    c_board[y1][x1] = 7;
    int y2 = -1, x2 = min_x + BLOCKS_COUNT[index][1][1];
    while (true) {
        int y = y2 + deltaY[2], x = x2 + deltaX[2];

        if (y >= MAX_Y)
            break;
        if (c_board[y][x] != 0)
            break;

        y2 = y, x2 = x;
    }

    if (y2 == -1)
        return false;

    c_board[y1][x1] = 203;
    c_board[y2][x2] = 203;

    int yy1 = min_y + BLOCKS_COUNT[index][0][0], xx1 = min_x + BLOCKS_COUNT[index][0][1];
    int yy2 = min_y + BLOCKS_COUNT[index][1][0], xx2 = min_x + BLOCKS_COUNT[index][1][1];

    if (c_board[yy1][xx1] != 203 || c_board[yy2][xx2] != 203)
        return false;

    for (auto &pos: vec)
        board[pos.first][pos.second] = 0;

    Answer++;
    return true;
}

int solution(vector<vector<int>> board) {
    MAX_Y = board.size(), MAX_X = board[0].size();

    while (true) {
        bool flag = false;
        for (int y = 0; y < MAX_Y; ++y) {
            for (int x = 0; x < MAX_X; ++x) {
                if (board[y][x] == 0)
                    continue;

                if (!visited[y][x] && bfs(board[y][x], y, x, board))
                    flag = true;
            }
        }

        if (!flag)
            break;
        
        memset(visited, 0, sizeof(visited));
    }

    return Answer;
}