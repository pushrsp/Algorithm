#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CCTV {
    int y, x, type, dir = -1;
};

int N, M, answer = INT32_MAX;
vector<vector<CCTV>> ORIGIN, TEMP;
vector<CCTV> cctv;

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};
int rotation[6] = {-1, 4, 4, 4, 4, 1};

void check_dir(int dir, int nowY, int nowX, int offset, vector<vector<CCTV>> &map) {
    int d = (dir + offset) % 4;
    int nextY = nowY + deltaY[d];
    int nextX = nowX + deltaX[d];

    while (true) {
        if (nextY < 0 || nextY >= N)
            break;
        if (nextX < 0 || nextX >= M)
            break;
        if (map[nextY][nextX].type == 6)
            break;

        //cctv 통과
        if (0 < map[nextY][nextX].type && map[nextY][nextX].type < 6) {
            nextY += deltaY[d];
            nextX += deltaX[d];
            continue;
        }

        map[nextY][nextX].type = -1;
        nextY += deltaY[d];
        nextX += deltaX[d];
    }
}

void count_map() {
    vector<vector<CCTV>> map(ORIGIN);
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x].type == 0 || map[y][x].type == 6)
                continue;

            switch (map[y][x].type) {
                case 1: // 오
                    check_dir(map[y][x].dir, y, x, 3, map);
                    break;
                case 2: // 오 왼
                    check_dir(map[y][x].dir, y, x, 3, map);
                    check_dir(map[y][x].dir, y, x, 1, map);
                    break;
                case 3: // 위 오
                    check_dir(map[y][x].dir, y, x, 3, map);
                    check_dir(map[y][x].dir, y, x, 2, map);
                    break;
                case 4: // 왼 위 오
                    check_dir(map[y][x].dir, y, x, 2, map);
                    check_dir(map[y][x].dir, y, x, 0, map);
                    check_dir(map[y][x].dir, y, x, 3, map);
                    break;
                case 5: // 위 왼 아 오
                    check_dir(map[y][x].dir, y, x, 3, map);
                    check_dir(map[y][x].dir, y, x, 0, map);
                    check_dir(map[y][x].dir, y, x, 1, map);
                    check_dir(map[y][x].dir, y, x, 2, map);
                    break;
            }
        }
    }

    int sum = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x].type == 0)
                sum++;
        }
    }

    answer = min(answer, sum);
}

void dfs(int idx) {
    if (idx == cctv.size()) {
        count_map();
        return;
    }

    int type = cctv[idx].type;
    for (int i = 0; i < rotation[type]; ++i) {
        int y = cctv[idx].y;
        int x = cctv[idx].x;

        ORIGIN[y][x].dir = i;
        dfs(idx + 1);
        ORIGIN[y][x].dir = cctv[idx].dir;
    }
}

int main() {
    cin >> N >> M;

    ORIGIN = vector<vector<CCTV>>(N, vector<CCTV>(M));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> ORIGIN[y][x].type;

            if (0 < ORIGIN[y][x].type && ORIGIN[y][x].type < 6) {
                ORIGIN[y][x].dir = 0;
                cctv.push_back({y, x, ORIGIN[y][x].type, ORIGIN[y][x].dir});
            }
        }
    }

    dfs(0);

    cout << answer << endl;
    return 0;
}