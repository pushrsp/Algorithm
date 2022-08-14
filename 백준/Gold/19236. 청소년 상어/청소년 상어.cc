#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> BOARD;
int answer = 0;

//위 위왼, 왼, 아왼, 아, 아오, 오, 위오
int deltaY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int deltaX[8] = {0, -1, -1, -1, 0, 1, 1, 1};

tuple<int, int, int> get_pos(int dir, int nowY, int nowX) {
    int cnt = 0;
    while (cnt < 8) {
        int nextY = nowY + deltaY[dir];
        int nextX = nowX + deltaX[dir];

        if ((0 <= nextY && nextY < 4) && (0 <= nextX && nextX < 4) && (BOARD[nextY][nextX].first != -1))
            return {nextY, nextX, dir};

        dir = (dir + 1) % 8;
        cnt++;
    }

    return {-1, -1, -1};
}

void move_fish() {
    int fish = 1;

    while (fish <= 16) {
        for (int y = 0; y < 4; ++y) {
            bool find = false;
            for (int x = 0; x < 4; ++x) {
                if (BOARD[y][x].first == fish) {
                    auto nextPos = get_pos(BOARD[y][x].second, y, x);

                    int nextY = get<0>(nextPos);
                    int nextX = get<1>(nextPos);
                    int nextDir = get<2>(nextPos);

                    find = true;

                    if (nextY == -1)
                        break;

                    BOARD[y][x].second = nextDir;
                    swap(BOARD[y][x], BOARD[nextY][nextX]);
                    break;
                }
            }

            if (find)
                break;
        }

        fish++;
    }
}

void DFS(int nowY, int nowX, int dir, int sum) {
    answer = max(answer, sum);

    vector<vector<pair<int, int>>> temp(BOARD);
    move_fish();

    for (int i = 1; i <= 3; ++i) {
        int nextY = nowY + deltaY[dir] * i;
        int nextX = nowX + deltaX[dir] * i;

        if ((0 <= nextY && nextY < 4) && (0 <= nextX && nextX < 4) && (BOARD[nextY][nextX].first != 0)) {
            int fish = BOARD[nextY][nextX].first;

            BOARD[nowY][nowX] = {0, 0};
            BOARD[nextY][nextX] = {-1, BOARD[nextY][nextX].second};

            DFS(nextY, nextX, BOARD[nextY][nextX].second, sum + fish);

            BOARD[nowY][nowX] = {-1, dir};
            BOARD[nextY][nextX] = {fish, BOARD[nextY][nextX].second};

        }
    }

    BOARD = vector<vector<pair<int, int>>>(temp);
}

int main() {
    BOARD = vector<vector<pair<int, int>>>(4, vector<pair<int, int>>(4));

    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            cin >> BOARD[y][x].first >> BOARD[y][x].second;
            BOARD[y][x].second--;
        }
    }

    int fish = BOARD[0][0].first;
    BOARD[0][0] = {-1, BOARD[0][0].second};

    DFS(0, 0, BOARD[0][0].second, fish);

    cout << answer << endl;
    return 0;
}