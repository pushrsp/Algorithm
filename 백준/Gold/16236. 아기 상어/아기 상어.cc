#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    bool operator<(const Pos &other) const {
        if (dist == other.dist) {
            if (y == other.y)
                return x > other.x;
            return y > other.y;
        }

        return dist > other.dist;
    }

    int y;
    int x;
    int dist;
};

int N;
vector<vector<int>> adj;
queue<Pos> q;

//위 왼쪽 아래 오른쪽
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};


int main() {
    cin >> N;

    adj = vector<vector<int>>(N, vector<int>(N, 0));

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> adj[y][x];

            if (adj[y][x] == 9) {
                adj[y][x] = 0;
                q.push({y, x, 0});
            }
        }
    }

    int size = 2, time = 0, exp = 0;
    while (true) {
        priority_queue<Pos> fish;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        while (!q.empty()) {
            Pos now = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextY = now.y + deltaY[i];
                int nextX = now.x + deltaX[i];

                if (nextY < 0 || nextY >= N)
                    continue;
                if (nextX < 0 || nextX >= N)
                    continue;
                if (visited[nextY][nextX])
                    continue;
                if (adj[nextY][nextX] > size)
                    continue;

                visited[nextY][nextX] = true;
                q.push({nextY, nextX, now.dist + 1});

                if (adj[nextY][nextX] != 0 && adj[nextY][nextX] < size)
                    fish.push({nextY, nextX, now.dist + 1});
            }
        }

        if (fish.empty())
            break;

        Pos selected = fish.top();
        if (++exp == size) {
            exp = 0;
            size++;
        }

        adj[selected.y][selected.x] = 0;
        q.push({selected.y, selected.x, 0});
        time += selected.dist;
    }

    cout << time << endl;

    return 0;
}