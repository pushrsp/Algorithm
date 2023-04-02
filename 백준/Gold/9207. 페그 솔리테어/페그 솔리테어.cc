#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
char Map[5][9];
vector<pair<int, int>> Pins, Candidates;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

bool InRange(int y, int x) {
    return 0 <= y && y < 5 && 0 <= x && x < 9;
}

void go(int count, int total) {
    Candidates.emplace_back(total, count);

    for (auto &pin: Pins) {
        if (Map[pin.first][pin.second] != 'o')
            continue;

        int curY = pin.first, curX = pin.second;
        for (int i = 0; i < 4; ++i) {
            int nextY = pin.first + DY[i], nextX = pin.second + DX[i];
            if (!InRange(nextY, nextX))
                continue;
            if (Map[nextY][nextX] != 'o')
                continue;

            int nextY2 = nextY + DY[i], nextX2 = nextX + DX[i];
            if (!InRange(nextY2, nextX2))
                continue;
            if (Map[nextY2][nextX2] != '.')
                continue;

            Map[nextY][nextX] = '.';
            Map[nextY2][nextX2] = 'o';
            Map[curY][curX] = '.';
            pin.first = nextY2, pin.second = nextX2;

            go(count + 1, total - 1);

            pin.first = curY, pin.second = curX;
            Map[curY][curX] = 'o';
            Map[nextY2][nextX2] = '.';
            Map[nextY][nextX] = 'o';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int y = 0; y < 5; ++y) {
            for (int x = 0; x < 9; ++x) {
                cin >> Map[y][x];

                if (Map[y][x] == 'o')
                    Pins.emplace_back(y, x);
            }
        }

        go(0, Pins.size());

        sort(Candidates.begin(), Candidates.end(), cmp_pair);

        cout << Candidates[0].first << ' ' << Candidates[0].second << '\n';

        Candidates.clear();
        Pins.clear();
    }

    return 0;
}