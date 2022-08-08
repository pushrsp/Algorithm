#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<string> BOARD;

//아오 아 아왼
int deltaY[3] = {1, 1, 1};
int deltaX[3] = {1, 0, -1};

int main() {
    cin >> T;

    for (int t = 0; t < T; ++t) {
        cin >> N;

        int answer = 0;
        BOARD = vector<string>(2);
        for (int i = 0; i < 2; ++i) {
            cin >> BOARD[i];

            for (char &s: BOARD[i]) {
                if (s == '*')
                    answer++;
            }
        }

        for (int n = 0; n < N; ++n) {
            if (BOARD[0][n] == '0')
                continue;

            int cnt = BOARD[0][n] - '0';
            for (int i = 0; i < 3; ++i) {
                int nextY = deltaY[i];
                int nextX = n + deltaX[i];

                if (cnt == 0)
                    break;

                if (nextX < 0 || nextX >= N)
                    continue;

                if (BOARD[nextY][nextX] == '*')
                    cnt--;
            }

            for (int i = 0; i < 3; ++i) {
                int nextY = deltaY[i];
                int nextX = n + deltaX[i];

                if (cnt == 0)
                    break;

                if (nextX < 0 || nextX >= N)
                    continue;

                if (BOARD[nextY][nextX] == '#') {
                    BOARD[nextY][nextX] = '*';
                    answer++;
                    cnt--;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}