#include <iostream>
#include <queue>

using namespace std;

struct Pos {
public:
    Pos operator+(const Pos &other) const {
        Pos ret{y + other.y, x + other.x};
        return ret;
    }

    bool operator==(const Pos &other) const {
        return y == other.y && x == other.x;
    }

    bool operator<(const Pos &other) const {
        if (y != other.y)
            return y < other.y;

        return x < other.x;
    }

public:
    int y;
    int x;
};

int M, N;
int graph[1001][1001];
int day[1001][1001];
queue<Pos> q;

Pos delta[4] = {
        Pos{-1, 0}, //위
        Pos{1, 0}, //아래
        Pos{0, -1}, //왼쪽
        Pos{0, 1}, //오른쪽
};

void BFS() {
    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();

        for (auto i: delta) {
            Pos next = pos + i;

            if (next.y < 1 || next.y > N)
                continue;
            if (next.x < 1 || next.x > M)
                continue;
            if (graph[next.y][next.x] != 0)
                continue;

            graph[next.y][next.x] = 1;
            day[next.y][next.x] = day[pos.y][pos.x] + 1;
            q.push(next);
        }
    }
}

int main() {
    cin >> M >> N;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            cin >> graph[y][x];

            if (graph[y][x] == 1)
                q.push(Pos{y, x});
        }
    }

    BFS();

    int result = 0;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            if (graph[y][x] == 0) {
                cout << -1 << endl;
                return 0;
            }

            if (day[y][x] > result)
                result = day[y][x];
        }
    }

    cout << result << endl;
    return 0;
}