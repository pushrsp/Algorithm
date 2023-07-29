#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K, Y, X, Board[129][129], Color;

bool check(int x, int y, int offset) {
    for (int i = x; i < x + offset; ++i) {
        for (int j = y; j < y + offset; ++j) {
            if (Board[i][j] != 0)
                return false;
        }
    }

    return true;
}

void go(int x, int y, int len) {
    ++Color;
    int half = len / 2;

    if (check(x, y, half))
        Board[x + half - 1][y + half - 1] = Color;
    if (check(x, y + half, half))
        Board[x + half - 1][y + half] = Color;
    if (check(x + half, y, half))
        Board[x + half][y + half - 1] = Color;
    if (check(x + half, y + half, half))
        Board[x + half][y + half] = Color;

    if (len == 2)
        return;

    go(x, y, half);
    go(x + half, y, half);
    go(x, y + half, half);
    go(x + half, y + half, half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K;
    cin >> X >> Y;

    Board[Y - 1][X - 1] = -1;

    go(0, 0, (1 << K));

    for (int y = (1 << K) - 1; y >= 0; --y) {
        for (int x = 0; x < (1 << K); ++x) {
            cout << Board[y][x] << ' ';
        }
        cout << '\n';
    }
    return 0;
}