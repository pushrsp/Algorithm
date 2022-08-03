#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, ANSWER = 0;
vector<vector<int>> BOARD;

//위 왼 아 오 위왼 위오 아왼 아오
int deltaY[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int deltaX[8] = {0, -1, 0, 1, -1, 1, -1, 1};

void BFS(int y, int x) {
    bool find = false;

    for (int i = 0; i < 8; ++i) {
        int nextY = y + deltaY[i];
        int nextX = x + deltaX[i];

        if (BOARD[nextY][nextX] == 0) {
            find = true;
            ANSWER--;
            break;
        }
    }

    if (!find) {
        for (int i = 0; i < 8; ++i) {
            int nextY = y + deltaY[i];
            int nextX = x + deltaX[i];

            if (0 < BOARD[nextY][nextX] && BOARD[nextY][nextX] < 9)
                BOARD[nextY][nextX]--;
        }
    }
}

int main() {
    cin >> N;

    BOARD = vector<vector<int>>(N, vector<int>(N));
    vector<pair<int, int>> pos;

    for (int n = 0; n < N; ++n) {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                BOARD[n][i] = -1;
                pos.emplace_back(n, i);
                ANSWER++;
            } else {
                BOARD[n][i] = s[i] - '0';
            }
        }
    }

    for (auto &p: pos)
        BFS(p.first, p.second);

    cout << ANSWER << endl;

    return 0;
}