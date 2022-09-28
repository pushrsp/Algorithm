#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<char>> Map;
vector<vector<int>> Visited;

int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Map = vector<vector<char>>(N, vector<char>(M));
    Visited = vector<vector<int>>(N, vector<int>(M));

    int startY, startX, destY, destX;
    cin >> startY >> startX >> destY >> destX;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> Map[y][x];
        }
    }

    startY--;
    startX--;
    destY--;
    destX--;

    queue<int> q;

    q.push(1000 * startY + startX);
    Visited[startY][startX] = 1;

    int cnt = 0;
    while (Map[destY][destX] != '0') {
        cnt++;
        queue<int> qq;
        while (!q.empty()) {
            int nowY = q.front() / 1000;
            int nowX = q.front() % 1000;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextY = nowY + deltaY[i];
                int nextX = nowX + deltaX[i];

                if (nextY < 0 || nextY >= N)
                    continue;
                if (nextX < 0 || nextX >= M)
                    continue;
                if (Visited[nextY][nextX])
                    continue;

                Visited[nextY][nextX] = cnt;
                if (Map[nextY][nextX] != '0') {
                    Map[nextY][nextX] = '0';
                    qq.push(1000 * nextY + nextX);
                } else {
                    q.push(1000 * nextY + nextX);
                }
            }
        }
        q = qq;
    }

    cout << Visited[destY][destX] << '\n';

    return 0;
}