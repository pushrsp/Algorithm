#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<bool>> BOARD;

int main() {
    cin >> N;

    BOARD = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int n = 0; n < N; ++n) {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'T')
                BOARD[n][i] = true;
        }
    }

    int answer = 400;
    for (int i = 0; i < (1 << N) - 1; ++i) {
        int sum = 0;

        for (int x = 0; x < N; ++x) {
            int flipCnt = 0;
            for (int y = 0; y < N; ++y) {
                bool isFlip = BOARD[y][x];
                if ((i & (1 << y)) != 0)
                    isFlip = !BOARD[y][x];

                if (isFlip)
                    flipCnt++;
            }

            sum += min(flipCnt, N - flipCnt);
        }

        answer = min(answer, sum);
    }

    cout << answer << endl;

    return 0;
}