#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, T, UP_Y = -1, DOWN_Y = -1;
vector<vector<int>> BOARD, TEMP, ADD;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void expand_dust(int y, int x) {
    int amount = BOARD[y][x] / 5;
    int cnt = 0;

    for (int i = 0; i < 4; ++i) {
        int nextY = y + deltaY[i];
        int nextX = x + deltaX[i];

        if (nextY < 0 || nextY >= R)
            continue;
        if (nextX < 0 || nextX >= C)
            continue;
        if (BOARD[nextY][nextX] == -1)
            continue;

        if (BOARD[nextY][nextX] == 0)
            TEMP[nextY][nextX] += amount;
        else
            ADD[nextY][nextX] += amount;

        cnt++;
    }

    TEMP[y][x] -= amount * cnt;
}

void move_dust_clock() {
    queue<int> q;

    int dir = 3, y = UP_Y, x = 1;
    q.push(TEMP[y][x]);
    TEMP[y][x] = 0;

    while (true) {
        int nextY = y + deltaY[dir];
        int nextX = x + deltaX[dir];

        if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) {
            dir = (dir + 1) % 4;
            continue;
        }

        if (TEMP[nextY][nextX] == -1)
            break;

        y = nextY;
        x = nextX;

        q.push(TEMP[y][x]);
        TEMP[y][x] = q.front();
        q.pop();
    }
}

void move_dust_counter_clock() {
    queue<int> q;

    int dir = 3, y = DOWN_Y, x = 1;
    q.push(TEMP[y][x]);
    TEMP[y][x] = 0;

    while (true) {
        int nextY = y + deltaY[dir];
        int nextX = x + deltaX[dir];

        if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) {
            dir--;
            continue;
        }

        if (TEMP[nextY][nextX] == -1)
            break;

        y = nextY;
        x = nextX;

        q.push(TEMP[y][x]);
        TEMP[y][x] = q.front();
        q.pop();
    }
}

int main() {
    cin >> R >> C >> T;

    BOARD = vector<vector<int>>(R, vector<int>(C, 0));
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> BOARD[y][x];

            if (BOARD[y][x] == -1) {
                if (UP_Y == -1)
                    UP_Y = y;
                else
                    DOWN_Y = y;
            }
        }
    }

    while (T--) {
        TEMP = vector<vector<int>>(BOARD);
        ADD = vector<vector<int>>(R, vector<int>(C, 0));
        for (int y = 0; y < R; ++y) {
            for (int x = 0; x < C; ++x) {
                if (BOARD[y][x] > 0)
                    expand_dust(y, x);

            }
        }

        for (int y = 0; y < R; ++y) {
            for (int x = 0; x < C; ++x) {
                TEMP[y][x] += ADD[y][x];
            }
        }

        move_dust_clock();
        move_dust_counter_clock();

        BOARD = vector<vector<int>>(TEMP);
    }

    int answer = 0;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (BOARD[y][x] > 0)
                answer += BOARD[y][x];
        }
    }

    cout << answer << endl;
    
    return 0;
}