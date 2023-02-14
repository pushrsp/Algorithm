#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <sstream>

#define INF 987654321

using namespace std;

vector<vector<int>> Map;
int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};

int Move(int startY, int startX, int destY, int destX) {
    int ret = Map[startY][startX];
    queue<int> q;

    q.push(Map[startY][startX]);

    int dir = 3;
    int nextY = startY + DY[dir], nextX = startX + DX[dir];
    while (true) {
        if (nextY == startY && nextX == startX)
            break;

        ret = min(ret, Map[nextY][nextX]);
        q.push(Map[nextY][nextX]);

        Map[nextY][nextX] = q.front();
        q.pop();

        switch (dir) {
            case 0:
                if (nextY == startY)
                    dir = (dir + 3) % 4;
                break;
            case 1:
                if (nextX == startX)
                    dir = (dir + 3) % 4;
                break;
            case 2:
                if (nextY == destY)
                    dir = (dir + 3) % 4;
                break;
            case 3:
                if (nextX == destX)
                    dir = (dir + 3) % 4;
                break;
        }

        nextY += DY[dir], nextX += DX[dir];
    }

    ret = min(ret, Map[nextY][nextX]);
    Map[nextY][nextX] = q.front();
    q.pop();

    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    Map = vector<vector<int>>(rows, vector<int>(columns));

    int num = 1;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x)
            Map[y][x] = num++;
    }

    vector<int> answer;
    for (auto &query: queries) {
        int y1 = query[0], x1 = query[1];
        int y2 = query[2], x2 = query[3];

        y1--, x1--, y2--, x2--;
        answer.push_back(Move(y1, x1, y2, x2));
    }

    return answer;
}