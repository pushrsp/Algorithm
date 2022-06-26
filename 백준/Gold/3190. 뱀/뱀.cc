#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K, L;
vector<vector<int>> MAP;
vector<pair<int, char>> v;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int Rotate(char c, int dir) {
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

void BFS() {
    deque<pair<int, int>> dq;

    int nowY = 0;
    int nowX = 0;
    int dir = 3;
    int time = 0;
    int idx = 0;

    dq.emplace_back(nowY, nowX);
    MAP[nowY][nowX] = 2;

    while (true) {
        time++;

        int nextY = nowY + deltaY[dir];
        int nextX = nowX + deltaX[dir];

        if (nextY < 0 || nextY >= N)
            break;
        if (nextX < 0 || nextX >= N)
            break;
        if (MAP[nextY][nextX] == 2)
            break;

        //이동한 칸에 사과가 없으면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        if (MAP[nextY][nextX] == 0) {
            MAP[nextY][nextX] = 2;
            MAP[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
            dq.emplace_front(nextY, nextX);
        } //이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        else if (MAP[nextY][nextX] == 1) {
            MAP[nextY][nextX] = 2;
            dq.emplace_front(nextY, nextX);
        }

        //방향 회전
        if (time == v[idx].first) {
            dir = Rotate(v[idx].second, dir);
            idx++;
        }

        nowY = nextY;
        nowX = nextX;
    }

    cout << time << endl;
}

int main() {
    cin >> N;
    MAP = vector<vector<int>>(N, vector<int>(N));

    cin >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        r -= 1;
        c -= 1;
        MAP[r][c] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; ++i) {
        int x;
        char c;
        cin >> x >> c;
        v.emplace_back(x, c);
    }

    BFS();

    return 0;
}