#include <iostream>
#include <vector>

using namespace std;

int R, C, CNT = 0;
vector<vector<char>> MAP;
vector<vector<bool>> visited;
bool done;

int deltaY[3] = {-1, 0, 1};
int deltaX[3] = {1, 1, 1};

void DFS(int y, int x) {
    visited[y][x] = true;
    if (x == C - 1) {
        done = true;
        CNT++;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        int nextY = y + deltaY[i];
        int nextX = x + deltaX[i];

        if (nextY < 0 || nextY >= R)
            continue;
        if (nextX < 0 || nextX >= C)
            continue;
        if (MAP[nextY][nextX] == 'x')
            continue;
        if (visited[nextY][nextX])
            continue;

        DFS(nextY, nextX);

        if (done)
            return;
    }
}

int main() {
    cin >> R >> C;

    MAP = vector<vector<char>>(R, vector<char>(C));
    visited = vector<vector<bool>>(R, vector<bool>(C, false));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> MAP[r][c];
        }
    }
    
    for (int y = 0; y < R; ++y) {
        done = false;
        DFS(y, 0);
    }

    cout << CNT << endl;
    return 0;
}