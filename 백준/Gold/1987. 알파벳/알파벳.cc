#include <iostream>
#include <queue>

using namespace std;

int R, C, Answer = -1;
vector<vector<char>> Map;
bool Visited[26];

int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void dfs(int nowY, int nowX, int cnt) {
    Answer = max(Answer, cnt);
    for (int i = 0; i < 4; ++i) {
        int nextY = nowY + deltaY[i];
        int nextX = nowX + deltaX[i];

        if (nextY < 0 || nextY >= R)
            continue;
        if (nextX < 0 || nextX >= C)
            continue;
        if (Visited[Map[nextY][nextX] - 'A'])
            continue;

        Visited[Map[nextY][nextX] - 'A'] = true;
        dfs(nextY, nextX, cnt + 1);
        Visited[Map[nextY][nextX] - 'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    Map = vector<vector<char>>(R, vector<char>(C));
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> Map[y][x];
        }
    }

    Visited[Map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << Answer << '\n';
    return 0;
}