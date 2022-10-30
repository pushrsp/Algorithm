#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> Map;

int deltaY[3] = {0, 1, 1};
int deltaX[3] = {1, 1, 0};

struct Pipe {
    int y, x, type;
};

/**
 * 0: 가로
 * 1: 세로
 * 2: 대각선
 */

bool check_diagonal(int nowY, int nowX, int destY, int destX) {
    bool success = true;
    for (int i = 0; i < 3; ++i) {
        int nextY = nowY + deltaY[i], nextX = nowX + deltaX[i];

        if (nextY > destY) {
            success = false;
            continue;
        }

        if (nextX > destX) {
            success = false;
            continue;
        }

        if (Map[nextY][nextX])
            success = false;
    }

    return success;
}

int bfs(int startY, int startX, int destY, int destX) {
    queue<Pipe> q;
    int count = 0;

    q.push({startY, startX, 0});
    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.y == destY && now.x == destX) {
            count++;
            continue;
        }

        if (now.type == 0) {
            if (now.x + 1 <= destX && !Map[now.y][now.x + 1])
                q.push({now.y, now.x + 1, 0});

            if (check_diagonal(now.y, now.x, destY, destX))
                q.push({now.y + 1, now.x + 1, 2});

        } else if (now.type == 1) {
            if (now.y + 1 <= destY && !Map[now.y + 1][now.x])
                q.push({now.y + 1, now.x, 1});

            if (check_diagonal(now.y, now.x, destY, destX))
                q.push({now.y + 1, now.x + 1, 2});
        } else {
            if (now.x + 1 <= destX && !Map[now.y][now.x + 1])
                q.push({now.y, now.x + 1, 0});

            if (now.y + 1 <= destY && !Map[now.y + 1][now.x])
                q.push({now.y + 1, now.x, 1});

            if (check_diagonal(now.y, now.x, destY, destX))
                q.push({now.y + 1, now.x + 1, 2});
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Map = vector<vector<int>>(N, vector<int>(N, 0));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Map[y][x];
        }
    }

    cout << bfs(0, 1, N - 1, N - 1) << '\n';
    return 0;
}