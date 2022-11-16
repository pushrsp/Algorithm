#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer = INT32_MAX;
int Visited[6] = {0, 5, 5, 5, 5, 5};
vector<vector<int>> Map;

void FillNum(int nowY, int nowX, int size, int fill) {
    for (int y = nowY; y < nowY + size; ++y) {
        for (int x = nowX; x < nowX + size; ++x) {
            Map[y][x] = fill;
        }
    }
}

bool Check(int nowY, int nowX, int size) {
    if (nowY + size > 10)
        return false;
    if (nowX + size > 10)
        return false;

    for (int y = nowY; y < nowY + size; ++y) {
        for (int x = nowX; x < nowX + size; ++x) {
            if (Map[y][x] == 0)
                return false;
        }
    }

    return true;
}

void go(int nowY, int nowX, int count) {
    if (count >= Answer)
        return;
    if (nowX == 10) {
        go(nowY + 1, 0, count);
        return;
    }

    if (nowY == 10) {
        Answer = min(Answer, count);
        return;
    }

    if (Map[nowY][nowX] == 0) {
        go(nowY, nowX + 1, count);
        return;
    }

    for (int i = 5; i >= 1; --i) {
        if (Visited[i] == 0)
            continue;

        if (Check(nowY, nowX, i)) {
            Visited[i]--;
            FillNum(nowY, nowX, i, 0);
            go(nowY, nowX + i, count + 1);
            FillNum(nowY, nowX, i, 1);
            Visited[i]++;
        }
    }
}

int main() {
    Map = vector<vector<int>>(10, vector<int>(10, 0));
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            cin >> Map[y][x];
        }
    }

    go(0, 0, 0);

    if (Answer == INT32_MAX)
        cout << -1 << '\n';
    else
        cout << Answer << '\n';

    return 0;
}