#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

struct Point {
    int w, y, x;

    bool operator<(const Point &other) const {
        return w > other.w;
    }
};

int N, M, Dist[502][502];
vector<Point> Map[502][502];

/*
 * 0: /
 * 1: \
 */

bool in_range(int y, int x) {
    return 1 <= y && y <= N && 1 <= x && x <= M;
}

void Di() {
    for (int y = 0; y <= N; ++y) {
        for (int x = 0; x <= M; ++x)
            Dist[y][x] = INF;
    }

    priority_queue<Point> pq;

    Dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        int y = pq.top().y;
        int x = pq.top().x;
        int w = pq.top().w;
        pq.pop();

        for (auto &next: Map[y][x]) {
            int ny = next.y;
            int nx = next.x;
            int nw = w + next.w;

            if (Dist[ny][nx] > nw) {
                Dist[ny][nx] = nw;
                pq.push({nw, ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    string s;
    for (int y = 0; y < N; ++y) {
        cin >> s;

        for (int x = 0; x < M; ++x) {
            if (s[x] == '/') {
                Map[y][x + 1].push_back({0, y + 1, x});
                Map[y + 1][x].push_back({0, y, x + 1});
                Map[y][x].push_back({1, y + 1, x + 1});
                Map[y + 1][x + 1].push_back({1, y, x});
            } else {
                Map[y][x].push_back({0, y + 1, x + 1});
                Map[y + 1][x + 1].push_back({0, y, x});
                Map[y][x + 1].push_back({1, y + 1, x});
                Map[y + 1][x].push_back({1, y, x + 1});
            }
        }
    }

    Di();

    if (Dist[N][M] == INF)
        cout << "NO SOLUTION" << '\n';
    else
        cout << Dist[N][M] << '\n';

    return 0;
}