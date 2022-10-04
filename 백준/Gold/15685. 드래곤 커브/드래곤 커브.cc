#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, deltaY[4] = {0, -1, 0, 1}, deltaX[4] = {1, 0, -1, 0};

vector<vector<int>> Map(101, vector<int>(101, 0));

/*
 * 0: 오
 * 1: 위
 * 2: 왼
 * 3: 아
 */

void draw_curve(int d, int g, int nowY, int nowX) {
    vector<int> dir;
    dir.push_back(d);

    for (int i = 0; i < g; ++i) {
        for (int j = dir.size() - 1; j >= 0; --j) {
            dir.push_back((dir[j] + 1) % 4);
        }
    }

    int nextY = nowY, nextX = nowX;
    Map[nextY][nextX] = 1;

    for (int dd: dir) {
        nextY += deltaY[dd], nextX += deltaX[dd];
        Map[nextY][nextX] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int n = 0; n < N; ++n) {
        int y, x, d, g;
        cin >> x >> y >> d >> g;

        draw_curve(d, g, y, x);
    }

    int answer = 0;
    for (int y = 0; y < 100; ++y) {
        for (int x = 0; x < 100; ++x) {
            if (Map[y][x] == 1 && Map[y][x + 1] == 1 && Map[y + 1][x] == 1 && Map[y + 1][x + 1] == 1)
                answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}