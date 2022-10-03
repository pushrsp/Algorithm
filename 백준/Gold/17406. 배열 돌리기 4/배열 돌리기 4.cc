#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int N, M, K, deltaY[4] = {-1, 0, 1, 0}, deltaX[4] = {0, -1, 0, 1}, Answer = INT32_MAX;

vector<vector<int>> Map;
vector<tuple<int, int, int>> Cmd, Temp;
bool Visited[7];

vector<vector<int>> rotate(vector<vector<int>> &map, int minY, int minX, int maxY, int maxX) {
    vector<vector<int>> ret(map);
    queue<int> q;

    int dir = 3, nowY = minY, nowX = minX;
    bool done = false;
    q.push(map[nowY][nowX]);

    while (!done) {
        int nextY = nowY + deltaY[dir];
        int nextX = nowX + deltaX[dir];

        q.push(map[nextY][nextX]);
        ret[nextY][nextX] = q.front();
        q.pop();

        switch (dir) {
            case 0:
                if (nextY == minY)
                    done = true;
                break;
            case 1:
                if (nextX == minX)
                    dir = (dir + 3) % 4;
                break;
            case 2:
                if (nextY == maxY)
                    dir = (dir + 3) % 4;
                break;
            case 3:
                if (nextX == maxX)
                    dir = (dir + 3) % 4;
                break;
        }

        nowY = nextY, nowX = nextX;
    }

    return ret;
}

void go(int cnt) {
    if (cnt == Cmd.size()) {
        vector<vector<int>> temp(Map);
        for (auto &cmd: Temp) {
            int minY = get<0>(cmd) - get<2>(cmd) - 1;
            int minX = get<1>(cmd) - get<2>(cmd) - 1;
            int maxY = get<0>(cmd) + get<2>(cmd) - 1;
            int maxX = get<1>(cmd) + get<2>(cmd) - 1;

            while (!(minY + minX >= maxY + maxX)) {
                temp = rotate(temp, minY, minX, maxY, maxX);

                minY++;
                minX++;
                maxY--;
                maxX--;
            }
        }

        int sum = INT32_MAX;
        for (int y = 0; y < N; ++y) {
            int s = 0;
            for (int x = 0; x < M; ++x) {
                s += temp[y][x];
            }

            sum = min(sum, s);
        }

        Answer = min(Answer, sum);
        return;
    }

    for (int i = 0; i < Cmd.size(); ++i) {
        if (Visited[i])
            continue;

        Visited[i] = true;
        Temp.push_back(Cmd[i]);
        go(cnt + 1);
        Temp.pop_back();
        Visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    Map = vector<vector<int>>(N, vector<int>(M, 0));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> Map[y][x];
        }
    }


    for (int k = 0; k < K; ++k) {
        int r, c, s;
        cin >> r >> c >> s;
        Cmd.emplace_back(r, c, s);
    }

    go(0);
    cout << Answer << '\n';

    return 0;
}