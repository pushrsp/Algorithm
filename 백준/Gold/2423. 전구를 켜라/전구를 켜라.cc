#include <iostream>
#include <vector>
#include <map>
#include <deque>

#define INF 987654321

using namespace std;

int N, M, Dist[502][502][2];
vector<string> Circuit;
map<char, int> Conv;
int SY[4] = {1, -1, 0, 0}, SX[4] = {0, 0, 1, -1};
int DY[4] = {1, -1, 1, -1}, DX[4] = {1, -1, -1, 1};

/*
 * \: 0
 * /: 1
 */

bool in_range(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    Circuit = vector<string>(N);
    for (int y = 0; y < N; ++y)
        cin >> Circuit[y];

    Conv.insert(make_pair('\\', 0));
    Conv.insert(make_pair('/', 1));

    fill(&Dist[0][0][0], &Dist[0][0][0] + 502 * 502 * 2, INF);

    deque<vector<int>> dq;
    dq.push_back({0, 0, 0});

    if (Circuit[0][0] == '/')
        Dist[0][0][0] = 1;
    else
        Dist[0][0][0] = 0;

    while (!dq.empty()) {
        auto curr = dq.front();
        dq.pop_front();

        int cy = curr[0], cx = curr[1], cdir = curr[2];
        for (int i = 0; i < 4; ++i) { //상하좌우
            int ny = cy + SY[i], nx = cx + SX[i];
            if (!in_range(ny, nx))
                continue;

            int next_dist = Dist[cy][cx][cdir], next_dir = Conv[Circuit[ny][nx]];
            if (cdir == Conv[Circuit[ny][nx]]) {
                next_dist++;
                next_dir = (cdir + 1) % 2;
            }

            if (next_dist >= Dist[ny][nx][next_dir])
                continue;

            Dist[ny][nx][next_dir] = next_dist;
            if (next_dist == Dist[cy][cx][cdir])
                dq.push_front({ny, nx, next_dir});
            else
                dq.push_back({ny, nx, next_dir});
        }

        //대각선
        if (cdir == 0) {
            for (int i = 0; i < 2; ++i) {
                int ny = cy + DY[i], nx = cx + DX[i];
                if (!in_range(ny, nx))
                    continue;

                int next_dist = Dist[cy][cx][cdir], next_dir = Conv[Circuit[ny][nx]];
                if (cdir != next_dir)
                    next_dist++;
                if (next_dist >= Dist[ny][nx][cdir])
                    continue;

                Dist[ny][nx][cdir] = next_dist;
                if (next_dist == Dist[cy][cx][cdir])
                    dq.push_front({ny, nx, cdir});
                else
                    dq.push_back({ny, nx, cdir});
            }
        } else {
            for (int i = 2; i < 4; ++i) {
                int ny = cy + DY[i], nx = cx + DX[i];
                if (!in_range(ny, nx))
                    continue;
                int next_dist = Dist[cy][cx][cdir], next_dir = Conv[Circuit[ny][nx]];
                if (cdir != next_dir)
                    next_dist++;
                if (next_dist >= Dist[ny][nx][cdir])
                    continue;

                Dist[ny][nx][cdir] = next_dist;
                if (next_dist == Dist[cy][cx][cdir])
                    dq.push_front({ny, nx, cdir});
                else
                    dq.push_back({ny, nx, cdir});
            }
        }
    }

    int ret = Dist[N - 1][M - 1][0];
    if (ret != INF)
        cout << ret << '\n';
    else
        cout << "NO SOLUTION" << '\n';

    return 0;
}