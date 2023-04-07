#include <iostream>
#include <vector>

using namespace std;

int N, K, Answer, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
vector<vector<int>> Board;
vector<vector<int>> Score;
vector<int> Bullets;

bool InRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

vector<pair<int, int>> GetEmptyPos(int y, int x, vector<vector<int>> &board) {
    vector<pair<int, int>> ret;

    for (int i = 0; i < 4; ++i) {
        int nextY = y + DY[i], nextX = x + DX[i];

        if (!InRange(nextY, nextX))
            continue;
        if (board[nextY][nextX] != 0)
            continue;

        ret.emplace_back(nextY, nextX);
    }

    return ret;
}

void go(int k, int sum, vector<vector<int>> board, vector<vector<int>> score) {
    if (k == K) {
        Answer = max(Answer, sum);
        return;
    }

    for (int y = 0; y < N; ++y) {
        vector<vector<int>> temp_board(board);
        vector<vector<int>> temp_score(score);

        int x = 0;
        int option = 0;

        while (x < N) {
            if (1 <= temp_board[y][x] && temp_board[y][x] <= 9) {
                option = 1;
                break;
            } else if (temp_board[y][x] >= 10) {
                option = 2;
                break;
            }

            x++;
        }

        int plus = 0;
        if (option == 1) {
            temp_board[y][x] = max(temp_board[y][x] - Bullets[k], 0);

            if (temp_board[y][x] == 0) {
                plus = temp_score[y][x];
                temp_score[y][x] = 0;

                vector<pair<int, int>> empty_pos = GetEmptyPos(y, x, temp_board);
                for (auto &pos: empty_pos) {
                    temp_board[pos.first][pos.second] = plus / 4;
                    temp_score[pos.first][pos.second] = plus / 4;
                }
            }
        } else if (option == 2) {
            plus = temp_board[y][x];
            temp_board[y][x] = 0;
        }

        go(k + 1, sum + plus, temp_board, temp_score);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> K;

    Board = vector<vector<int>>(N, vector<int>(N, 0));
    Score = vector<vector<int>>(N, vector<int>(N, 0));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Board[y][x];

            if (1 <= Board[y][x] && Board[y][x] <= 9)
                Score[y][x] = Board[y][x];
        }
    }

    Bullets = vector<int>(K);
    for (int i = 0; i < K; ++i)
        cin >> Bullets[i];

    go(0, 0, Board, Score);

    cout << Answer << '\n';
    return 0;
}