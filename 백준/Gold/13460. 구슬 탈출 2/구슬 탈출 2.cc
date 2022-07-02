#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct INFO {
    int ry, rx, by, bx, count;
};

INFO start;
int N = 0, M = 0;
vector<vector<char>> MAP;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int BFS() {
    queue<INFO> q;
    bool visited[10][10][10][10] = {false,};

    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = true;

    int ret = -1;
    while (!q.empty()) {
        INFO now = q.front();
        q.pop();

        //10개가 넘으면 무조건 -1 리턴
        if (now.count > 10)
            break;

        //빨간볼이 O에 도착, 파랑볼이 O에 없으면 조건 완료
        if (MAP[now.ry][now.rx] == 'O' && MAP[now.by][now.bx] != 'O') {
            ret = now.count;
            break;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nextRy = now.ry;
            int nextRx = now.rx;
            int nextBy = now.by;
            int nextBx = now.bx;

            //빨간볼 움직임
            while (true) {
                if (MAP[nextRy][nextRx] != '#' && MAP[nextRy][nextRx] != 'O') {
                    nextRy += deltaY[dir];
                    nextRx += deltaX[dir];
                } else {
                    if (MAP[nextRy][nextRx] == '#') {
                        nextRy -= deltaY[dir];
                        nextRx -= deltaX[dir];
                    }

                    break;
                }
            }

            //파랑볼 움직임
            while (true) {
                if (MAP[nextBy][nextBx] != '#' && MAP[nextBy][nextBx] != 'O') {
                    nextBy += deltaY[dir];
                    nextBx += deltaX[dir];
                } else {
                    if (MAP[nextBy][nextBx] == '#') {
                        nextBy -= deltaY[dir];
                        nextBx -= deltaX[dir];
                    }

                    break;
                }
            }

            //빨간볼과 파란볼의 위치가 겹칠경우
            if (nextRy == nextBy && nextRx == nextBx) {
                if (MAP[nextRy][nextRx] != 'O') {
                    int red_dist = abs(nextRy - now.ry) + abs(nextRx - now.rx);
                    int blue_dist = abs(nextBy - now.by) + abs(nextBx - now.bx);

                    if (red_dist > blue_dist) {
                        nextRy -= deltaY[dir];
                        nextRx -= deltaX[dir];
                    } else {
                        nextBy -= deltaY[dir];
                        nextBx -= deltaX[dir];
                    }
                }
            }

            if (!visited[nextRy][nextRx][nextBy][nextBx]) {
                visited[nextRy][nextRx][nextBy][nextBx] = true;

                q.push({nextRy, nextRx, nextBy, nextBx, now.count + 1});
            }
        }
    }

    return ret;
}

int main() {
    cin >> N >> M;

    MAP = vector<vector<char>>(N, vector<char>(M));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> MAP[y][x];

            if (MAP[y][x] == 'R')
                start.ry = y, start.rx = x;
            if (MAP[y][x] == 'B')
                start.by = y, start.bx = x;
        }
    }

    start.count = 0;
    cout << BFS() << endl;

    return 0;
}