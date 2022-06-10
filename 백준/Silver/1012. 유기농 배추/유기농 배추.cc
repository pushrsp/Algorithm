#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int C;
int Y, X, J;
vector<vector<int>> adj;
vector<vector<bool>> visited;

//위 왼쪽 아래 오른쪽
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextX < 0)
                continue;
            if (nextY >= Y || nextX >= X)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (adj[nextY][nextX] == 0)
                continue;

            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
        }
    }
}

int main() {
    cin >> C;
    for (int i = 0; i < C; ++i) {
        cin >> X >> Y >> J;

        adj = vector<vector<int>>(Y, vector<int>(X));
        visited = vector<vector<bool>>(Y, vector<bool>(X));
        for (int j = 0; j < J; ++j) {
            int x, y;
            cin >> x >> y;
            adj[y][x] = 1;
        }

        int cnt = 0;
        for (int y = 0; y < Y; ++y) {
            for (int x = 0; x < X; ++x) {
                if (adj[y][x] == 1 && !visited[y][x]) {
                    BFS(y, x);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
