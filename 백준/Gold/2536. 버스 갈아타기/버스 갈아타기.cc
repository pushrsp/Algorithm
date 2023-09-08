#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct Bus {
    int x1, y1, x2, y2;

    bool in_range(int x, int y) const {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }

    bool in_range(const Bus &other) const {
        return x1 <= other.x2 && other.x1 <= x2 && y1 <= other.y2 && other.y1 <= y2;
    }
};

int M, N, K, SX, SY, DX, DY;
Bus Buses[5001];
int Dist[5001];

int bfs() {
    queue<int> q;
    for (int k = 0; k < K; ++k) {
        if (Buses[k].in_range(SX, SY)) {
            q.push(k);
            Dist[k] = 1;
        }
    }

    while (!q.empty()) {
        auto bus = q.front();
        q.pop();

        if (Buses[bus].in_range(DX, DY))
            return Dist[bus];

        for (int k = 0; k < K; ++k) {
            if (Dist[k] > 0)
                continue;

            if (Buses[bus].in_range(Buses[k])) {
                Dist[k] = Dist[bus] + 1;
                q.push(k);
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> M >> N;
    cin >> K;

    int b, x1, y1, x2, y2;
    for (int k = 0; k < K; ++k) {
        cin >> b >> x1 >> y1 >> x2 >> y2;

        if (y1 > y2)
            swap(y1, y2);
        if (x1 > x2)
            swap(x1, x2);

        Buses[k] = {x1, y1, x2, y2};
    }

    cin >> SX >> SY >> DX >> DY;

    cout << bfs() << '\n';

    return 0;
}