#include <vector>
#include <iostream>

using namespace std;

int ANSWER = 0;
vector<vector<int>> BOARD;

//위 왼 아 오 위왼 위오 아왼 아오
int deltaY[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int deltaX[8] = {0, -1, 0, 1, -1, 1, -1, 1};

bool check_queen(int n, int y, int x) {

    for (int i = 0; i < 8; ++i) {
        int curY = y;
        int curX = x;

        while (true) {
            int nextY = curY + deltaY[i];
            int nextX = curX + deltaX[i];

            if (nextY < 0 || nextY >= n)
                break;
            if (nextX < 0 || nextX >= n)
                break;
            if (BOARD[nextY][nextX] == 1)
                return false;

            curY = nextY;
            curX = nextX;
        }
    }

    return true;
}

void comb(int cnt, int y, int n) {
    if (cnt == n) {
        ANSWER++;
        return;
    } else {
        for (int x = 0; x < n; ++x) {
            if (check_queen(n, y, x)) {
                BOARD[y][x] = 1;
                comb(cnt + 1, y + 1, n);
                BOARD[y][x] = 0;
            }
        }
    }
}

int solution(int n) {
    BOARD = vector<vector<int>>(n, vector<int>(n, 0));
    comb(0, 0, n);

    cout << ANSWER << endl;
    return ANSWER;
}