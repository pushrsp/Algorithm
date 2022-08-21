#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Puyo {
    int y, x;
    char c;
};

vector<string> BOARD(12);
vector<vector<bool>> visited;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

bool BFS(int curY, int curX, char curC) {
    queue<Puyo> q;
    vector<Puyo> path;

    visited[curY][curX] = true;
    q.push({curY, curX, curC});
    path.push_back({curY, curX, curC});

    while (!q.empty()) {
        Puyo now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];

            if (nextY < 0 || nextY >= 12)
                continue;
            if (nextX < 0 || nextX >= 6)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (BOARD[nextY][nextX] == '.')
                continue;
            if (BOARD[nextY][nextX] != now.c)
                continue;

            visited[nextY][nextX] = true;
            q.push({nextY, nextX, now.c});
            path.push_back({nextY, nextX, now.c});
        }
    }

    if (path.size() >= 4) {
        for (Puyo &puyo: path)
            BOARD[puyo.y][puyo.x] = '.';

        return true;
    }


    return false;
}

void move_board() {
    for (int y = 11; y >= 0; --y) {
        for (int x = 0; x < BOARD[y].size(); ++x) {
            if (BOARD[y][x] == '.')
                continue;

            int prevY = y;
            char c = BOARD[y][x];
            int nextY = y + deltaY[2];

            while (nextY < 12 && BOARD[nextY][x] == '.') {
                BOARD[nextY][x] = c;
                BOARD[prevY][x] = '.';

                prevY = nextY;
                nextY += deltaY[2];
            }
        }
    }
}

int main() {
    for (int i = 0; i < 12; ++i)
        cin >> BOARD[i];


    int cnt = 0;
    while (true) {
        visited = vector<vector<bool>>(12, vector<bool>(6, false));
        bool move = false;

        for (int y = 11; y >= 0; --y) {
            for (int x = 0; x < BOARD[y].size(); ++x) {
                if (BOARD[y][x] == '.' || visited[y][x])
                    continue;

                if (BFS(y, x, BOARD[y][x]))
                    move = true;
            }
        }

        if (move)
            cnt++;
        else
            break;

        move_board();
    }

    cout << cnt << endl;

    return 0;
}