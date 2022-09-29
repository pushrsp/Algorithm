#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int X, Y;
vector<vector<int>> Map;
int Visited[51][51], Comp[2501];

//왼 위 오 아
int deltaY[4] = {0, -1, 0, 1};
int deltaX[4] = {-1, 0, 1, 0};

int go(int nowY, int nowX, int idx) {
    int ret = 1;
    bool dir[4] = {false, false, false, false};
    Visited[nowY][nowX] = idx;

    for (int j = 0; j < 4; ++j) {
        if (Map[nowY][nowX] & (1 << j))
            dir[j] = true;
    }

    for (int i = 0; i < 4; ++i) {
        if (dir[i])
            continue;

        int nextY = nowY + deltaY[i];
        int nextX = nowX + deltaX[i];

        if (nextY < 0 || nextY >= Y)
            continue;
        if (nextX < 0 || nextX >= X)
            continue;
        if (Visited[nextY][nextX])
            continue;

        ret += go(nextY, nextX, idx);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;

    Map = vector<vector<int>>(Y, vector<int>(X));
    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            cin >> Map[y][x];
        }
    }

    int idx = 1;
    int mx = -1;
    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            if (!Visited[y][x]) {
                idx++;
                Comp[idx] = go(y, x, idx);
                mx = max(mx, Comp[idx]);
            }
        }
    }

    int sum = 0;
    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            if (y + 1 < Y) {
                int a1 = Visited[y + 1][x], a2 = Visited[y][x];
                if (a1 != a2)
                    sum = max(sum, Comp[a1] + Comp[a2]);
            }

            if (x + 1 < X) {
                int a1 = Visited[y][x + 1], a2 = Visited[y][x];
                if (a1 != a2)
                    sum = max(sum, Comp[a1] + Comp[a2]);
            }
        }
    }

    cout << idx - 1 << '\n';
    cout << mx << '\n';
    cout << sum << '\n';
    return 0;
}