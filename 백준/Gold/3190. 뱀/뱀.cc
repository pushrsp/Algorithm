#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K, L, DIR = 3, TIME = 0, IDX = 0;
vector<vector<int>> MAP;
vector<pair<int, char>> ROTATE;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int get_dir(char c, int dir) {
    if (c == 'L') {
        return (dir + 1) % 4;
    } else {
        if (dir == 0)
            return 3;
        else if (dir == 1)
            return 0;
        else if (dir == 2)
            return 1;
        else
            return 2;
    }
}

int main() {
    cin >> N;
    MAP = vector<vector<int>>(N, vector<int>(N, 0));

    cin >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        MAP[r - 1][c - 1] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; ++i) {
        int x;
        char c;
        cin >> x >> c;

        ROTATE.emplace_back(x, c);
    }

    deque<pair<int, int>> dq;
    dq.emplace_back(0, 0);
    MAP[0][0] = 2;

    while (true) {
        TIME++;

        int nowY = dq.front().first;
        int nowX = dq.front().second;

        int nextY = nowY + deltaY[DIR];
        int nextX = nowX + deltaX[DIR];

        if (nextY < 0 || nextY >= N)
            break;
        if (nextX < 0 || nextX >= N)
            break;

        // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        if (MAP[nextY][nextX] == 0) {
            MAP[nextY][nextX] = 2;
            MAP[dq.back().first][dq.back().second] = 0;

            dq.pop_back();
            dq.emplace_front(nextY, nextX);
        }// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        else if (MAP[nextY][nextX] == 1) {
            MAP[nextY][nextX] = 2;

            dq.emplace_front(nextY, nextX);
        } // 자기자신의 몸과 부딪히면 게임이 끝난다
        else {
            break;
        }

        //방향 회전
        if (TIME == ROTATE[IDX].first) {
            DIR = get_dir(ROTATE[IDX].second, DIR);
            IDX++;
        }
    }

    cout << TIME << endl;
    return 0;
}