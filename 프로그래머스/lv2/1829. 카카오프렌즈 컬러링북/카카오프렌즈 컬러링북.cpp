#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAX 101

using namespace std;

int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
bool Visited[MAX][MAX];

bool InRange(int y, int x, int maxY, int maxX) {
    return 0 <= y && y < maxY && 0 <= x && x < maxX;
}

int BFS(int nowY, int nowX, int maxY, int maxX, vector<vector<int>> &picture, int color) {
    queue<pair<int, int>> q;

    Visited[nowY][nowX] = true;
    q.emplace(nowY, nowX);

    int ret = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = cur.first + DY[i], nextX = cur.second + DX[i];

            if (!InRange(nextY, nextX, maxY, maxX))
                continue;
            if (picture[nextY][nextX] != color)
                continue;
            if (Visited[nextY][nextX])
                continue;

            ret += 1;
            q.emplace(nextY, nextX);
            Visited[nextY][nextX] = true;
        }
    }

    return ret;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            Visited[y][x] = false;
        }
    }

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            if (!Visited[y][x] && picture[y][x] != 0) {
                int size = BFS(y, x, m, n, picture, picture[y][x]);
                max_size_of_one_area = max(max_size_of_one_area, size);
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}