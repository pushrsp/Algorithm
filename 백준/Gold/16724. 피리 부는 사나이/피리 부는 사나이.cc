#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1}, N, M;
int Answer = 0, Discovered[1001][1001];
bool Finished[1001][1001];
vector<string> Map;

int GetDir(char c) {
    switch (c) {
        case 'U':
            return 0;
        case 'L':
            return 1;
        case 'D':
            return 2;
        default:
            return 3;
    }
}

void go(int nowY, int nowX, int order) {
    Discovered[nowY][nowX] = 1;

    int dir = GetDir(Map[nowY][nowX]);
    int nextY = nowY + DY[dir], nextX = nowX + DX[dir];

    if (Discovered[nextY][nextX] == 0)
        go(nextY, nextX, order + 1);
    else if (!Finished[nextY][nextX])
        ++Answer;

    Finished[nowY][nowX] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    Map = vector<string>(N);

    if (N == 1 && M == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 0; i < N; ++i)
        cin >> Map[i];

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (Discovered[y][x] == 0)
                go(y, x, 1);
        }
    }

    cout << Answer << '\n';
    return 0;
}