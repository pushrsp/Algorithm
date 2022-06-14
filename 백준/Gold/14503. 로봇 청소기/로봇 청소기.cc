#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
public:
    int y;
    int x;
};

int Y, X;
int startY, startX, startDir;
vector<vector<int>> adj;
vector<vector<bool>> visited;

//위 오른쪽 아래 왼쪽
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, 1, 0, -1};


void BFS(Pos pos, int dir) {
    queue<pair<Pos, int>> q;

    q.push({pos, dir});
    visited[pos.y][pos.x] = true;
    int cleanCnt = 1;

    while (!q.empty()) {
        pos = q.front().first;
        dir = q.front().second;

        q.pop();

        bool clean = false;
        for (int i = 0; i < 4; ++i) {
            int nextDir = (dir + 3) % 4;
            int nextY = pos.y + deltaY[nextDir];
            int nextX = pos.x + deltaX[nextDir];

            if (nextY < 0 || nextY >= Y) {
                dir = nextY;
                continue;
            }

            if (nextX < 0 || nextX >= X) {
                dir = nextDir;
                continue;
            }

            if (adj[nextY][nextX] == 1) {
                dir = nextDir;
                continue;
            }

            if (visited[nextY][nextX]) {
                dir = nextDir;
                continue;
            }

            clean = true;
            visited[nextY][nextX] = true;
            q.push({{nextY, nextX}, nextDir});
            cleanCnt++;
            break;
        }

        //UP:LEFT, LEFT:DOWN, DOWN:RIGHT, RIGHT:UP
        if (!clean) {
            int y = pos.y - deltaY[dir];
            int x = pos.x - deltaX[dir];

            if (adj[y][x] == 0)
                q.push({{y, x}, dir});
        }
    }

    cout << cleanCnt << endl;
}

int main() {
    cin >> Y >> X;
    cin >> startY >> startX >> startDir;

    adj = vector<vector<int>>(Y, vector<int>(X));
    visited = vector<vector<bool>>(Y, vector<bool>(X));

    Pos pos{startY, startX};

    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            cin >> adj[y][x];
        }
    }

    BFS(pos, startDir);
    return 0;
}