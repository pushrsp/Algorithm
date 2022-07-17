#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, Y, K;
vector<vector<int>> MAP;
queue<int> ORDER;

//동 서 북 남
int deltaY[4] = {0, 0, -1, 1};
int deltaX[4] = {1, -1, 0, 0};

vector<int> dice(7); // 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면

void rollEast() {
    dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

void rollWest() {
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

void rollNorth() {
    dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

void rollSouth() {
    dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

int main() {
    cin >> N >> M >> X >> Y >> K;

    MAP = vector<vector<int>>(N, vector<int>(M, 0));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> MAP[y][x];
        }
    }

    for (int k = 0; k < K; ++k) {
        int o;
        cin >> o;

        ORDER.push(o);
    }

    int nowY = X;
    int nowX = Y;
    while (!ORDER.empty()) {
        int order = ORDER.front();
        ORDER.pop();

        int nextY = nowY + deltaY[order - 1];
        int nextX = nowX + deltaX[order - 1];

        if (nextY < 0 || nextY >= N)
            continue;
        if (nextX < 0 || nextX >= M)
            continue;

        switch (order) {
            case 1:
                rollEast();
                break;
            case 2:
                rollWest();
                break;
            case 3:
                rollNorth();
                break;
            case 4:
                rollSouth();
                break;
        }

        if (MAP[nextY][nextX] > 0) {
            dice[6] = MAP[nextY][nextX];
            MAP[nextY][nextX] = 0;
        } else {
            MAP[nextY][nextX] = dice[6];
        }

        nowY = nextY;
        nowX = nextX;

        cout << dice[1] << endl;
    }
    return 0;
}