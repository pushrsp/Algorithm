#include <iostream>
#include <queue>

using namespace std;

/*
 * 1 익은 토마토
 * 0 익지 않은 토마토
 * -1 토마토가 들어있지 않은 칸
 */

struct Pos {
public:
    Pos operator+(const Pos &other) const {
        Pos ret{y + other.y, z + other.z, x + other.x};
        return ret;
    }

    bool operator==(const Pos &other) const {
        return y == other.y && z == other.z && x == other.x;
    }

    bool operator<(const Pos &other) const {
        if (y != other.y)
            return y < other.y;
        else if (z != other.z)
            return z < other.z;
        else
            return x < other.x;
    }

public:
    int y;
    int z;
    int x;
};

int M, N, H;
int tomato[101][101][101];
int day[101][101][101];
queue<Pos> q;

Pos delta[6] = {
        Pos{-1, 0, 0}, //위
        Pos{1, 0, 0}, //아래
        Pos{0, 0, -1}, //왼쪽
        Pos{0, 0, 1}, //오른쪽
        Pos{0, 1, 0}, //앞
        Pos{0, -1, 0}, //뒤
};

void BFS() {
    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();

        for (auto i: delta) {
            Pos next = pos + i;

            if (next.y < 1 || next.y > H)
                continue;
            if (next.z < 1 || next.z > N)
                continue;
            if (next.x < 1 || next.x > M)
                continue;
            if (tomato[next.y][next.z][next.x] != 0)
                continue;

            tomato[next.y][next.z][next.x] = 1;
            day[next.y][next.z][next.x] = day[pos.y][pos.z][pos.x] + 1;
            q.push(next);
        }
    }
}

int main() {
    cin >> M >> N >> H;

    for (int y = 1; y <= H; ++y) {
        for (int z = 1; z <= N; ++z) {
            for (int x = 1; x <= M; ++x) {
                cin >> tomato[y][z][x];

                if (tomato[y][z][x] == 1)
                    q.push(Pos{y, z, x});
            }
        }
    }

    BFS();

    int result = 0;
    for (int y = 1; y <= H; ++y) {
        for (int z = 1; z <= N; ++z) {
            for (int x = 1; x <= M; ++x) {
                if (tomato[y][z][x] == 0) {
                    cout << -1 << endl;
                    return 0;
                }

                if (day[y][z][x] > result)
                    result = day[y][z][x];
            }
        }
    }

    cout << result << endl;
    return 0;
}