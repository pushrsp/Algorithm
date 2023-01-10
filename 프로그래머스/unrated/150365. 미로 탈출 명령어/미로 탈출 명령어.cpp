#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

#define MAX 51

using namespace std;

struct Point {
    int y, x;
    string history;
};

int N, M, K, DY[4] = {1, 0, 0, -1}, DX[4] = {0, -1, 1, 0};
bool Visited[MAX][MAX][2501][4];
char Dir[4] = {'d', 'l', 'r', 'u'};

bool cmp_str(const string &a, const string &b) {
    return a + b < b + a;
}

bool InRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

string BFS(int startY, int startX, int destY, int destX) {
    queue<Point> q;
    vector<string> temp;

    for (int i = 0; i < 4; ++i) {
        int nextY = startY + DY[i], nextX = startX + DX[i];
        if (!InRange(nextY, nextX))
            continue;

        Visited[nextY][nextX][1][i] = true;
        string history;
        q.push({nextY, nextX, history + Dir[i]});
    }

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.y == destY && now.x == destX && now.history.length() == K) {
            temp.push_back(now.history);
            continue;
        }

        if (now.history.length() + 1 > K)
            continue;

        for (int i = 0; i < 4; ++i) {
            int nextY = now.y + DY[i], nextX = now.x + DX[i];

            if (!InRange(nextY, nextX))
                continue;
            if (Visited[nextY][nextX][now.history.length() + 1][i])
                continue;

            Visited[nextY][nextX][now.history.length() + 1][i] = true;
            q.push({nextY, nextX, now.history + Dir[i]});
        }
    }

    if (temp.empty())
        return "impossible";

    sort(temp.begin(), temp.end(), cmp_str);
    return temp[0];
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int dist = ::abs(x - r) + ::abs(y - c);
    if (dist > k)
        return "impossible";
    
    x--, y--, r--, c--;
    N = n, M = m, K = k;

    return BFS(x, y, r, c);
}