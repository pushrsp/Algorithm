#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Y, X, MAX = 0;
vector<vector<char>> adj;
vector<vector<bool>> visited;
vector<vector<int>> dist;

//위 왼쪽 아래 오른쪽
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void BFS(int _y, int _x) {
    visited = vector<vector<bool>>(Y, vector<bool>(X));
    dist = vector<vector<int>>(Y, vector<int>(X));

    queue<pair<int, int>> q;
    q.push({_y, _x});
    visited[_y][_x] = true;
    dist[_y][_x] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = y + deltaY[i];
            int nextX = x + deltaX[i];

            if (nextY < 0 || nextY >= Y)
                continue;
            if (nextX < 0 | nextX >= X)
                continue;
            if (adj[nextY][nextX] == 'W')
                continue;
            if (visited[nextY][nextX])
                continue;

            visited[nextY][nextX] = true;
            dist[nextY][nextX] = dist[y][x] + 1;
            q.push({nextY, nextX});
            if (MAX < dist[nextY][nextX])
                MAX = dist[nextY][nextX];
        }
    }
}

int main() {
    cin >> Y >> X;

    adj = vector<vector<char>>(Y, vector<char>(X));

    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            cin >> adj[y][x];
        }
    }

    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            if (adj[y][x] == 'L') {
                BFS(y, x);
            }
        }
    }

    cout << MAX << endl;

    return 0;
}