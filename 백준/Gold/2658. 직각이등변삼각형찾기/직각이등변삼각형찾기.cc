#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int BOARD[10][10];
pair<int, int> answer[3];

void rotate() {
    int tmp[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            tmp[i][j] = BOARD[i][j];
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            BOARD[i][j] = tmp[9 - j][i];
        }
    }
}

bool find_one() {
    int y = -1, x = -1;

    for (int i = 0; i < 10; ++i) {
        bool found = false;
        for (int j = 0; j < 10; ++j) {
            if (BOARD[i][j] == 1) {
                y = i;
                x = j;
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    if (y == -1 || x == -1)
        return false;

    answer[0] = {y, x};

    int tmp[10][10];
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i + y < 10; ++i) {
        if (BOARD[i + y][x] == 1) {
            if (x - i < 0 || x + i >= 10)
                return false;

            answer[1] = {y + i, x - i};
            answer[2] = {y + i, x + i};

            for (int j = x - i; j <= x + i; ++j) {
                tmp[i + y][j] = 1;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (tmp[i][j] != BOARD[i][j])
                return false;
        }
    }
    return true;
}

bool find_two() {
    int y = -1, x = -1;

    for (int i = 0; i < 10; ++i) {
        bool found = false;
        for (int j = 0; j < 10; ++j) {
            if (BOARD[i][j] == 1) {
                y = i;
                x = j;
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    if (y == -1 || x == -1)
        return false;

    answer[0] = {y, x};

    int tmp[10][10];
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i + y < 10; ++i) {
        if (BOARD[i + y][x] == 1) {
            if (x - i < 0)
                return false;

            answer[1] = {y + i, x};
            answer[2] = {y + i, x - i};

            for (int j = x - i; j <= x; ++j) {
                tmp[i + y][j] = 1;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (tmp[i][j] != BOARD[i][j])
                return false;
        }
    }

    return true;
}

void rotate_point(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int y = answer[j].first, x = answer[j].second;
            answer[j].first = 9 - x;
            answer[j].second = y;
        }
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%1d", &BOARD[i][j]);
        }
    }

    for (int q = 0; q < 4; ++q) {
        rotate();

        if (find_one()) {
            rotate_point(q + 1);
            sort(answer, answer + 3);

            for (int i = 0; i < 3; ++i) {
                cout << answer[i].first + 1 << " " << answer[i].second + 1 << endl;
            }
            return 0;
        }

        if (find_two()) {
            rotate_point(q + 1);
            sort(answer, answer + 3);

            for (int i = 0; i < 3; ++i) {
                cout << answer[i].first + 1 << " " << answer[i].second + 1 << endl;
            }
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}