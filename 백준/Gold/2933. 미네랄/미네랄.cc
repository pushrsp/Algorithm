#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define INF 984321

using namespace std;

int R, C, N, DY[4] = {-1, 0, 1, 0}, DX[4] = {0, -1, 0, 1};
vector<vector<char>> Map;
vector<int> Cmd;
bool Visited[101][101];
bool Cluster[101][101];

bool InRange(int y, int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}

bool BreakMineral(char dir, int nowY) {
    if (dir == 'L') {
        for (int i = 0; i < C; ++i) {
            if (Map[nowY][i] == 'x') {
                Map[nowY][i] = '.';
                return true;
            }
        }
    } else {
        for (int i = C - 1; i >= 0; --i) {
            if (Map[nowY][i] == 'x') {
                Map[nowY][i] = '.';
                return true;
            }
        }
    }

    return false;
}

void BFS(int nowY, int nowX) {
    queue<pair<int, int>> q;

    Visited[nowY][nowX] = true;
    q.emplace(nowY, nowX);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = now.first + DY[i], nextX = now.second + DX[i];

            if (!InRange(nextY, nextX))
                continue;
            if (Map[nextY][nextX] != 'x')
                continue;
            if (Visited[nextY][nextX])
                continue;

            Visited[nextY][nextX] = true;
            q.emplace(nextY, nextX);
        }
    }
}

vector<pair<int, int>> FindCluster() {
    for (int x = 0; x < C; ++x) {
        if (Map[R - 1][x] == 'x' && !Visited[R - 1][x])
            BFS(R - 1, x);
    }

    vector<pair<int, int>> ret;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (Map[y][x] == 'x' && !Visited[y][x])
                ret.emplace_back(y, x), Cluster[y][x] = true;
        }
    }

    return ret;
}

int Gravity(int nowY, int nowX) {
    int ret = 0;
    for (int y = nowY + 1; y < R; ++y) {
        if (Map[y][nowX] == 'x') {
            if (Cluster[y][nowX])
                return INF;
            else
                return ret;
        } else {
            ret += 1;
        }
    }

    return ret;
}

void Reset(vector<pair<int, int>> &clusters) {
    if (clusters.empty())
        return;

    int min_height = INT32_MAX;
    for (auto &cluster: clusters)
        min_height = min(min_height, Gravity(cluster.first, cluster.second));

    sort(clusters.begin(), clusters.end());
    for (int i = clusters.size() - 1; i >= 0; --i) {
        Map[clusters[i].first][clusters[i].second] = '.';
        Map[clusters[i].first + min_height][clusters[i].second] = 'x';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C;
    Map = vector<vector<char>>(R, vector<char>(C));

    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> Map[y][x];
        }
    }

    cin >> N;
    Cmd = vector<int>(N);

    for (int i = 0; i < N; ++i)
        cin >> Cmd[i];

    for (int i = 0; i < N; ++i) {
        if (!BreakMineral(i % 2 == 0 ? 'L' : 'R', R - Cmd[i]))
            continue;

        vector<pair<int, int>> cluster = FindCluster();
        Reset(cluster);

        ::memset(Visited, false, sizeof(Visited));
        ::memset(Cluster, false, sizeof(Cluster));
    }

    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cout << Map[y][x];
        }
        cout << '\n';
    }

    return 0;
}