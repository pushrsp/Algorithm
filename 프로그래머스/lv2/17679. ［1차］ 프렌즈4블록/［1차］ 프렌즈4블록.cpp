#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

int MAX_Y, MAX_X;
int deltaY[4] = {1, 0, 1, 0};
int deltaX[4] = {0, 1, 1, 0};

bool Check(int nowY, int nowX, vector<string> &board) {
    for (int i = 0; i < 3; ++i) {
        int nextY = nowY + deltaY[i], nextX = nowX + deltaX[i];

        if (nextY >= MAX_Y || nextX >= MAX_X)
            return false;
        if (board[nextY][nextX] != board[nowY][nowX])
            return false;
    }

    return true;
}

int RemoveBlocks(vector<pair<int, int>> &pos, vector<string> &board) {
    int ret = 0;
    for (auto &p: pos) {
        for (int i = 0; i < 4; ++i) {
            int nextY = p.first + deltaY[i], nextX = p.second + deltaX[i];

            if (board[nextY][nextX] == '.')
                continue;

            board[nextY][nextX] = '.';
            ret += 1;
        }
    }

    return ret;
}

void Move(vector<string> &board) {
    for (int y = MAX_Y - 1; y >= 0; --y) {
        for (int x = 0; x < MAX_X; ++x) {
            if (board[y][x] == '.')
                continue;

            int nextY = y + deltaY[0], nextX = x + deltaX[0];
            int prevY = y, prevX = x;
            while (nextY < MAX_Y && board[nextY][nextX] == '.') {
                board[nextY][nextX] = board[prevY][prevX];
                board[prevY][prevX] = '.';
                prevY = nextY, prevX = nextX;
                nextY += deltaY[0], nextX += deltaX[0];
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    MAX_Y = m;
    MAX_X = n;
    int answer = 0;

    while (true) {
        vector<pair<int, int>> pos;
        for (int y = 0; y < MAX_Y; ++y) {
            for (int x = 0; x < MAX_X; ++x) {
                if (board[y][x] == '.')
                    continue;

                if (Check(y, x, board))
                    pos.emplace_back(y, x);
            }
        }

        if (pos.empty())
            break;

        answer += RemoveBlocks(pos, board);
        Move(board);
    }

    return answer;
}