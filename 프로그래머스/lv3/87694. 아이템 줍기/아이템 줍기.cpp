#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int y, x, dist;
};

vector<vector<int>> BOARD(120, vector<int>(120, 0));
vector<vector<bool>> visited(120, vector<bool>(120, false));

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    for (auto &rect: rectangle) {
        for (int &coord: rect)
            coord *= 2;

        int startX = rect[0], startY = rect[1];
        int endX = rect[2], endY = rect[3];

        for (int y = startY; y <= endY; ++y) {
            for (int x = startX; x <= endX; ++x) {
                BOARD[y][x] = 1;
            }
        }
    }

    for (auto &rect: rectangle) {
        int startX = rect[0], startY = rect[1];
        int endX = rect[2], endY = rect[3];

        for (int y = startY + 1; y < endY; ++y) {
            for (int x = startX + 1; x < endX; ++x) {
                BOARD[y][x] = 0;
            }
        }
    }

    queue<Node> q;

    visited[characterY][characterX] = true;
    q.push({characterY, characterX, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.y == itemY && now.x == itemX) {
            answer = now.dist;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];

            if (nextY < 0 || nextY >= 120)
                continue;
            if (nextX < 0 || nextX >= 120)
                continue;
            if (BOARD[nextY][nextX] != 1)
                continue;
            if (visited[nextY][nextX])
                continue;

            visited[nextY][nextX] = true;
            q.push({nextY, nextX, now.dist + 1});
        }
    }

    return answer / 2;
}