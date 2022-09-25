#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
vector<vector<int>> Map;
vector<vector<bool>> Visited;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int bfs(int nowY, int nowX) {
    queue<pair<int, int>> q;

    Visited[nowY][nowX] = true;
    q.push({nowY, nowX});

    int dist = 1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.first + deltaY[i];
            int nextX = now.second + deltaX[i];

            if (nextY < 0 || nextY >= M)
                continue;
            if (nextX < 0 || nextX >= N)
                continue;
            if (Map[nextY][nextX] != 0)
                continue;
            if (Visited[nextY][nextX])
                continue;

            Visited[nextY][nextX] = true;
            q.push({nextY, nextX});
            dist++;
        }
    }

    return dist;
}

int main() {
    cin >> M >> N >> K;

    Map = vector<vector<int>>(M, vector<int>(N, 0));
    Visited = vector<vector<bool>>(M, vector<bool>(N, false));

    for (int k = 1; k <= K; ++k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; ++y) {
            for (int x = x1; x < x2; ++x) {
                Map[y][x] = k;
            }
        }
    }

    vector<int> answer;
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            if (Map[y][x] == 0 && !Visited[y][x])
                answer.push_back(bfs(y, x));
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for (int a: answer)
        cout << a << " ";

    return 0;
}