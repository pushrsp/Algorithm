#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<vector<char>> Map;
int Dp[51][51], Visited[51][51];

//위 왼 아 오
int deltaY[4] = {-1, 0, 1, 0};
int deltaX[4] = {0, -1, 0, 1};

int go(int nowY, int nowX) {
    if (nowY < 0 || nowY >= N)
        return 0;
    if (nowX < 0 || nowX >= M)
        return 0;
    if (Map[nowY][nowX] == 'H')
        return 0;

    //사이클
    if (Visited[nowY][nowX]) {
        cout << -1 << '\n';
        exit(0);
    }

    int &ret = Dp[nowY][nowX];
    if (ret)
        return ret;

    Visited[nowY][nowX] = 1;
    int val = Map[nowY][nowX] - '0';

    for (int i = 0; i < 4; ++i) {
        int nextY = nowY + deltaY[i] * val, nextX = nowX + deltaX[i] * val;
        ret = max(ret, go(nextY, nextX) + 1);
    }
    
    Visited[nowY][nowX] = 0;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Map = vector<vector<char>>(N, vector<char>(M));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> Map[y][x];
        }
    }

    cout << go(0, 0) << '\n';

    return 0;
}