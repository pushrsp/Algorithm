#include <iostream>
#include <queue>

using namespace std;

int N, L, Answer = 0;
vector<vector<int>> Map1, Map2;

void go(vector<vector<int>> &map) {
    for (int i = 0; i < N; ++i) {
        int cnt = 1;
        int j;

        for (j = 0; j < N - 1; ++j) {
            if (map[i][j] == map[i][j + 1])
                cnt++;
            else if (map[i][j] + 1 == map[i][j + 1] && cnt >= L)
                cnt = 1;
            else if (map[i][j] - 1 == map[i][j + 1] && cnt >= 0)
                cnt = -L + 1;
            else
                break;
        }

        if (j == N - 1 && cnt >= 0)
            Answer++;
    }
}

int main() {
    cin >> N >> L;

    Map1 = vector<vector<int>>(N, vector<int>(N));
    Map2 = vector<vector<int>>(N, vector<int>(N));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Map1[y][x];
            Map2[x][y] = Map1[y][x];
        }
    }

    go(Map1);
    go(Map2);

    cout << Answer << '\n';
    return 0;
}