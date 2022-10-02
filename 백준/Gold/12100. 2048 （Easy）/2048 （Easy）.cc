#include <iostream>
#include <vector>

using namespace std;

int N, ANSWER = 0;

vector<vector<int>> move(vector<vector<int>> &map, int dir) {
    vector<vector<int>> temp(N, vector<int>(N, 0));

    switch (dir) {
        case 0:
            for (int x = 0; x < N; ++x) {
                int nextIdx = 0, target = -1;
                for (int y = 0; y < N; ++y) {
                    if (map[y][x] == 0)
                        continue;

                    if (map[y][x] == target) {
                        temp[nextIdx - 1][x] = map[y][x] * 2;
                        target = -1;
                        ANSWER = max(ANSWER, temp[nextIdx - 1][x]);
                    } else {
                        temp[nextIdx++][x] = map[y][x];
                        target = map[y][x];
                    }
                }
            }
            break;
        case 1:
            for (int x = 0; x < N; ++x) {
                int nextIdx = N - 1, target = -1;
                for (int y = N - 1; y >= 0; --y) {
                    if (map[y][x] == 0)
                        continue;

                    if (map[y][x] == target) {
                        temp[nextIdx + 1][x] = map[y][x] * 2;
                        target = -1;
                        ANSWER = max(ANSWER, temp[nextIdx + 1][x]);
                    } else {
                        temp[nextIdx--][x] = map[y][x];
                        target = map[y][x];
                    }
                }
            }
            break;
        case 2:
            for (int y = 0; y < N; ++y) {
                int nextIdx = 0, target = -1;
                for (int x = 0; x < N; ++x) {
                    if (map[y][x] == 0)
                        continue;

                    if (map[y][x] == target) {
                        temp[y][nextIdx - 1] = map[y][x] * 2;
                        target = -1;
                        ANSWER = max(ANSWER, temp[y][nextIdx - 1]);
                    } else {
                        temp[y][nextIdx++] = map[y][x];
                        target = map[y][x];
                    }
                }
            }
            break;
        default:
            for (int y = 0; y < N; ++y) {
                int nextIdx = N - 1, target = -1;
                for (int x = N - 1; x >= 0; --x) {
                    if (map[y][x] == 0)
                        continue;

                    if (map[y][x] == target) {
                        temp[y][nextIdx + 1] = map[y][x] * 2;
                        target = -1;
                        ANSWER = max(ANSWER, temp[y][nextIdx + 1]);
                    } else {
                        temp[y][nextIdx--] = map[y][x];
                        target = map[y][x];
                    }
                }
            }
            break;
    }

    return temp;
}

void DFS(vector<vector<int>> &map, int count) {
    if (count == 5)
        return;

    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> temp = move(map, i);
        DFS(temp, count + 1);
    }
}

int main() {
    cin >> N;

    vector<vector<int>> BOARD(N, vector<int>(N, 0));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> BOARD[y][x];
            ANSWER = max(ANSWER, BOARD[y][x]);
        }
    }
    
    DFS(BOARD, 0);

    cout << ANSWER << endl;

    return 0;
}