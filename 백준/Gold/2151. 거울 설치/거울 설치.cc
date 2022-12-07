#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
#define ll long long

using namespace std;

int N, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
vector<string> Map;
bool Visited[51][51][4];

struct Point {
    int y, x, dir, count;
};

struct Cmp {
    bool operator()(const Point &a, const Point &b) {
        return a.count > b.count;
    }
};

bool InRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int bfs(int startY, int startX, int destY, int destX) {
    priority_queue<Point, vector<Point>, Cmp> q;

    q.push({startY, startX, 0, 0});
    q.push({startY, startX, 1, 0});
    q.push({startY, startX, 2, 0});
    q.push({startY, startX, 3, 0});

    Visited[startY][startX][0] = true;
    Visited[startY][startX][1] = true;
    Visited[startY][startX][2] = true;
    Visited[startY][startX][3] = true;

    int ret = INT32_MAX;
    while (!q.empty()) {
        auto now = q.top();
        q.pop();

        if (now.count > ret)
            continue;

        int nextY = now.y + DY[now.dir], nextX = now.x + DX[now.dir];
        if (nextY == destY && nextX == destX) {
            ret = min(ret, now.count);
            continue;
        }

        if (!InRange(nextY, nextX))
            continue;
        if (Map[nextY][nextX] == '*')
            continue;
        if (Visited[nextY][nextX][now.dir])
            continue;

        Visited[nextY][nextX][now.dir] = true;
        if (Map[nextY][nextX] == '.') {
            q.push({nextY, nextX, now.dir, now.count});
        } else if (Map[nextY][nextX] == '!') {
            q.push({nextY, nextX, (now.dir + 3) % 4, now.count + 1});
            q.push({nextY, nextX, (now.dir + 1) % 4, now.count + 1});
            q.push({nextY, nextX, now.dir, now.count});
        }
    }

    return ret == INT32_MAX ? 0 : ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    Map = vector<string>(N);

    vector<pair<int, int>> temp;
    for (int i = 0; i < N; ++i) {
        cin >> Map[i];

        for (int j = 0; j < Map[i].length(); ++j) {
            if (Map[i][j] == '#')
                temp.emplace_back(i, j);
        }
    }

    cout << bfs(temp[0].first, temp[0].second, temp[1].first, temp[1].second) << '\n';
    return 0;
}