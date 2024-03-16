#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N, M, CY, CX;
int DY[4] = {-1, 0, 1, 0};
int DX[4] = {0, -1, 0, 1};
vector<string> Map;
bool Visited[666][666];

bool in_range(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void bfs(int startY, int startX) {
    queue<pair<int, int>> q;

    Visited[startY][startX] = true;
    q.emplace(startY, startX);

    int ret = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = curr.first + DY[i], nextX = curr.second + DX[i];

            if (!in_range(nextY, nextX))
                continue;
            if (Visited[nextY][nextX])
                continue;
            if (Map[nextY][nextX] == 'X')
                continue;

            q.emplace(nextY, nextX);
            Visited[nextY][nextX] = true;
            if (Map[nextY][nextX] == 'P')
                ret += 1;
        }
    }

    if (ret == 0)
        cout << "TT" << '\n';
    else
        cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Map = vector<string>(N);
    for (int y = 0; y < N; ++y) {
        cin >> Map[y];
        for (int x = 0; x < M; ++x) {
            if (Map[y][x] == 'I')
                CY = y, CX = x;
        }
    }

    bfs(CY, CX);

    return 0;
}