#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAX 301
#define INF 987654321

using namespace std;

struct Point {
    int c1, c2, dist;

    bool operator<(const Point &other) const {
        return dist < other.dist;
    }
};

int Visited[MAX][MAX], Parent[MAX * 1000], N, H, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
vector<vector<int>> Map;
vector<pair<int, int>> Component[MAX * 1000];
vector<Point> Points;

bool InRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int GetParent(int i) {
    if (Parent[i] == i)
        return i;

    return Parent[i] = GetParent(Parent[i]);
}

void Union(int a, int b) {
    a = GetParent(a), b = GetParent(b);
    if (a < b)
        Parent[b] = a;
    else
        Parent[a] = b;
}

void BFS(int startY, int startX, int color) {
    queue<pair<int, int>> q;

    Component[color].emplace_back(startY, startX);
    Visited[startY][startX] = color;
    q.emplace(startY, startX);

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = cur.first + DY[i], nextX = cur.second + DX[i];

            if (!InRange(nextY, nextX))
                continue;
            if (::abs(Map[cur.first][cur.second] - Map[nextY][nextX]) > H)
                continue;
            if (Visited[nextY][nextX] >= color)
                continue;

            Component[color].emplace_back(nextY, nextX);
            Visited[nextY][nextX] = color;
            q.emplace(nextY, nextX);
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    Map = land;
    N = Map.size();
    H = height;
    int color = 1;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (Visited[y][x] == 0) {
                BFS(y, x, color);
                color++;
            }
        }
    }

    for (int i = 1; i < color; ++i) {
        for (auto &node: Component[i]) {
            for (int j = 0; j < 4; ++j) {
                int nextY = node.first + DY[j], nextX = node.second + DX[j];
                if (!InRange(nextY, nextX))
                    continue;
                if (Visited[nextY][nextX] == i)
                    continue;

                int dist = ::abs(Map[node.first][node.second] - Map[nextY][nextX]);
                if (dist <= H)
                    continue;

                Points.push_back({i, Visited[nextY][nextX], dist});
            }
        }
    }

    for (int i = 0; i < MAX * 1000; ++i)
        Parent[i] = i;

    sort(Points.begin(), Points.end());

    int ret = 0;
    for (auto &point: Points) {
        if (GetParent(point.c1) != GetParent(point.c2)) {
            Union(point.c1, point.c2);
            ret += point.dist;
        }
    }

    return ret;
}