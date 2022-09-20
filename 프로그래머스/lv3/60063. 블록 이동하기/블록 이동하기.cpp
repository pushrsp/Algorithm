#include <string>
#include <vector>
#include <queue>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Point {
    int y, x, dir, time;
};

int D[4][2] = {
        {-1, 0},
        {1,  0},
        {0,  -1},
        {0,  1}
};

int R[2][4][2] = {
        {
                {1, 1},
                {1, -1},
                {-1, -1},
                {-1, 1},
        },
        {
                {1, -1},
                {-1, -1},
                {-1, 1},
                {1, 1},
        }
};

int C[2][4][2] = {
        {
                {-1, 1},
                {1, 1},
                {1, -1},
                {-1, -1},
        },
        {
                {-1, -1},
                {-1, 1},
                {1, 1},
                {1, -1},
        }
};

vector<vector<int>> BOARD;
int N;
queue<pair<Point, Point>> Q;
bool VISITED[101][101][4];

bool is_valid(Point point[2]) {
    for (int i = 0; i < 2; ++i) {
        if (point[i].y < 0 || point[i].y > N - 1 || point[i].x < 0 || point[i].x > N - 1)
            return false;
        if (BOARD[point[i].y][point[i].x] == 1)
            return false;
        if (VISITED[point[i].y][point[i].x][point[i].dir])
            return false;
    }

    return true;
}

int rotate(Point cur[2], int ccw, int idx) {
    Point newPt[2];
    int a = idx, b = (idx + 1) % 2;
    int dir = cur[a].dir;
    newPt[0] = {
            cur[a].y,
            cur[a].x,
            (cur[a].dir + (ccw ? 3 : 1)) % 4,
            cur[a].time + 1
    };
    newPt[1] = {
            cur[b].y + R[ccw][dir][0],
            cur[b].x + R[ccw][dir][1],
            (cur[b].dir + (ccw ? 3 : 1)) % 4,
            cur[a].time + 1
    };

    if (!is_valid(newPt))
        return 0;
    if (BOARD[cur[a].y + C[ccw][dir][0]][cur[a].x + C[ccw][dir][1]] == 1)
        return 0;

    for (auto &i: newPt) {
        if (i.y == N - 1 && i.x == N - 1)
            return i.time;

        VISITED[i.y][i.x][i.dir] = true;
    }

    Q.push({newPt[a], newPt[b]});
    return 0;
}

int solution(vector<vector<int>> board) {
    BOARD = board;
    N = board.size();

    Q.push({
                   {0, 0, RIGHT, 0},
                   {0, 1, LEFT,  0}
           });
    VISITED[0][0][RIGHT] = true;
    VISITED[0][1][LEFT] = true;

    while (!Q.empty()) {
        Point cur[2], newPt[2];
        cur[0] = Q.front().first;
        cur[1] = Q.front().second;

        Q.pop();

        for (auto &j: D) {
            for (int i = 0; i < 2; ++i) {
                newPt[i] = {
                        cur[i].y + j[0],
                        cur[i].x + j[1],
                        cur[i].dir,
                        cur[i].time + 1
                };
            }

            if (!is_valid(newPt))
                continue;

            for (auto &i: newPt) {
                if (i.y == N - 1 && i.x == N - 1)
                    return i.time;

                VISITED[i.y][i.x][i.dir] = true;
            }

            Q.push({newPt[0], newPt[1]});
        }

        for (int ccw = 0; ccw < 2; ++ccw) {
            for (int i = 0; i < 2; ++i) {
                int ret = rotate(cur, ccw, i);
                if (ret != 0)
                    return ret;
            }
        }
    }

    return 0;
}