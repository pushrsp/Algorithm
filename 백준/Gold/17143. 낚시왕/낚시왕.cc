#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, M, deltaY[5] = {0, -1, 1, 0, 0}, deltaX[5] = {0, 0, 0, 1, -1}, Fisherman = -1;

struct Shark {
    int y, x, s, d, z;
    bool alive;
};

vector<Shark> Sharks;
int Map[100][100];

void move_shark() {
    memset(Map, 0, sizeof(Map));
    vector<int> remove;

    for (int i = 0; i < Sharks.size(); i++) {
        if (!Sharks[i].alive)
            continue;

        int y = Sharks[i].y, x = Sharks[i].x, s = Sharks[i].s, d = Sharks[i].d, z = Sharks[i].z;

        int nextY, nextX;
        while (true) {
            nextY = y + s * deltaY[d];
            nextX = x + s * deltaX[d];

            if (nextX < C && nextY < R && nextY >= 0 && nextX >= 0)
                break;

            if (d == 1 && nextY < 0) {
                s -= y;
                y = 0;
                d = 2;
            } else if (d == 2 && nextY >= R) {
                s -= R - 1 - y;
                y = R - 1;
                d = 1;
            } else if (d == 3 && nextX >= C) {
                s -= C - 1 - x;
                x = C - 1;
                d = 4;
            } else if (d == 4 && nextX < 0) {
                s -= x;
                x = 0;
                d = 3;
            }
        }

        if (Map[nextY][nextX]) {
            if (Sharks[Map[nextY][nextX] - 1].z < z) {
                Sharks[Map[nextY][nextX] - 1].alive = false;
                Map[nextY][nextX] = i + 1;
            } else {
                Sharks[i].alive = false;
            }
        } else {
            Map[nextY][nextX] = i + 1;
        }

        Sharks[i].y = nextY, Sharks[i].x = nextX, Sharks[i].d = d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;

    for (int m = 0; m < M; ++m) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;

        y--;
        x--;

        Sharks.push_back({y, x, s, d, z, true});
    }

    if (M == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int answer = 0;
    while (Fisherman < C) {
        Fisherman++;
        int removeIdx = -1;
        for (int i = 0; i < R; ++i) {
            bool find = false;
            for (int j = 0; j < Sharks.size(); ++j) {
                if (!Sharks[j].alive)
                    continue;

                if (Sharks[j].y == i && Sharks[j].x == Fisherman) {
                    removeIdx = j;
                    answer += Sharks[j].z;
                    find = true;
                    break;
                }
            }

            if (find)
                break;
        }

        if (removeIdx != -1)
            Sharks.erase(Sharks.begin() + removeIdx);

        move_shark();
    }

    cout << answer << '\n';

    return 0;
}