#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> Map;
vector<vector<bool>> Visited;
int N;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

void bfs(int nowY, int nowX, int amount) {
    queue<pair<int, int>> q;

    Visited[nowY][nowX] = true;
    q.push({nowY, nowX});

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.first + deltaY[i];
            int nextX = now.second + deltaX[i];

            if (nextY < 0 || nextY >= N)
                continue;
            if (nextX < 0 || nextX >= N)
                continue;
            if (Map[nextY][nextX] < amount)
                continue;
            if (Visited[nextY][nextX])
                continue;

            Visited[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
}

int main() {
    cin >> N;

    Map = vector<vector<int>>(N, vector<int>(N, 0));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Map[y][x];
        }
    }

    int amount = 1;
    int answer = 0;
    while (amount <= 100) {
        Visited = vector<vector<bool>>(N, vector<bool>(N, false));
        int cnt = 0;

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (Map[y][x] >= amount && !Visited[y][x]) {
                    bfs(y, x, amount);
                    cnt++;
                }
            }
        }

        answer = max(answer, cnt);
        amount++;
    }

    cout << answer << endl;

    return 0;
}