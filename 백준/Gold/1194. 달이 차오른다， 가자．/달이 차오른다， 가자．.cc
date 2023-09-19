#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
vector<vector<char>> Board;
pair<int, int> Start;
bool Visited[51][51][1 << 6];

bool in_range(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

bool has_key(int key, char gate) {
    return key & (1 << (gate - 'A'));
}

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;

    q.emplace(make_pair(Start.first, Start.second), make_pair(0, 0));
    Visited[Start.first][Start.second][0] = true;

    while (!q.empty()) {
        int curr_y = q.front().first.first;
        int curr_x = q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;
        q.pop();

        if (Board[curr_y][curr_x] == '1')
            return cnt;

        for (int i = 0; i < 4; ++i) {
            int nextY = curr_y + DY[i], nextX = curr_x + DX[i];

            if (!in_range(nextY, nextX))
                continue;
            if (Visited[nextY][nextX][key])
                continue;

            if (Board[nextY][nextX] == '.' || Board[nextY][nextX] == '1') {
                Visited[nextY][nextX][key] = true;
                q.emplace(make_pair(nextY, nextX), make_pair(cnt + 1, key));
            } else if ('a' <= Board[nextY][nextX] && Board[nextY][nextX] <= 'f') {
                int next_key = key | (1 << (int) (Board[nextY][nextX] - 'a'));
                Visited[nextY][nextX][next_key] = true;
                q.emplace(make_pair(nextY, nextX), make_pair(cnt + 1, next_key));
            } else if ('A' <= Board[nextY][nextX] && Board[nextY][nextX] <= 'F') {
                if (has_key(key, Board[nextY][nextX])) {
                    Visited[nextY][nextX][key] = true;
                    q.emplace(make_pair(nextY, nextX), make_pair(cnt + 1, key));
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Board = vector<vector<char>>(N, vector<char>(M));

    string s;
    for (int n = 0; n < N; ++n) {
        cin >> s;

        for (int m = 0; m < M; ++m) {
            Board[n][m] = s[m];
            if (Board[n][m] == '0') {
                Start.first = n;
                Start.second = m;
                Board[n][m] = '.';
            }
        }
    }

    cout << bfs() << '\n';

    return 0;
}