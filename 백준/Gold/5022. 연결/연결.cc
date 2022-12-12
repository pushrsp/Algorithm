#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

struct Point {
    int y, x, dist;
};

struct Cmp {
    bool operator()(const Point& a, const Point& b) const {
        return a.dist > b.dist;
    }
};

int N, M, DY[4] = {-1,0,1,0}, DX[4] = {0,-1,0,1};
vector<vector<int>> Points(2, vector<int>(4));
bool Visited[101][101];

int bfs(int startY, int startX, int destY, int destX) {
    priority_queue<Point, vector<Point>, Cmp> pq;
    vector<int> route[101][101];

    pq.push({startY, startX, 0});
    route[startY][startX] = {startY, startX};

    bool flag = false;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if(now.y == destY && now.x == destX) {
            flag = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + DY[i], nextX = now.x + DX[i];

            if(nextY < 0 || nextY > M)
                continue;
            if(nextX < 0 || nextX > N)
                continue;
            if(Visited[nextY][nextX])
                continue;
            if(!route[nextY][nextX].empty())
                continue;

            route[nextY][nextX] = {now.y, now.x};
            pq.push({nextY, nextX, now.dist + 1});
        }
    }

    if(!flag)
        return -1;

    int ret = 0;
    int curY = destY, curX = destX;

    while (route[curY][curX][0] != curY || route[curY][curX][1] != curX) {
        ret += 1;
        Visited[curY][curX] = true;

        int prevY = curY;
        curY = route[prevY][curX][0], curX = route[prevY][curX][1];
    }

    Visited[curY][curX] = true;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> Points[i][j];
        }
    }

    int answer = INT32_MAX;

    Visited[Points[1][1]][Points[1][0]] = true;
    Visited[Points[1][3]][Points[1][2]] = true;
    int d1 = bfs(Points[0][1], Points[0][0], Points[0][3], Points[0][2]);

    Visited[Points[1][1]][Points[1][0]] = false;
    Visited[Points[1][3]][Points[1][2]] = false;
    int d2 = bfs(Points[1][1], Points[1][0], Points[1][3], Points[1][2]);

    if(d1 > 0 && d2 > 0)
        answer = min(answer, d1 + d2);

    ::memset(Visited, false, sizeof(Visited));

    Visited[Points[0][1]][Points[0][0]] = true;
    Visited[Points[0][3]][Points[0][2]] = true;
    int d3 = bfs(Points[1][1], Points[1][0], Points[1][3], Points[1][2]);

    Visited[Points[0][1]][Points[0][0]] = false;
    Visited[Points[0][3]][Points[0][2]] = false;
    int d4 = bfs(Points[0][1], Points[0][0], Points[0][3], Points[0][2]);

    if(d3 > 0 && d4 > 0)
        answer = min(answer, d3 + d4);

    if(answer == INT32_MAX)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << answer << '\n';
    return 0;
}