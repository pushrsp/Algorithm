#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int N, M;
int Table[1025][1025], FenTree[1025][1025];

void Update(int nowY, int nowX, int num) {
    for (int y = nowY; y <= N; y += (y & -y)) {
        for (int x = nowX; x <= N; x += (x & -x)) {
            FenTree[y][x] += num;
        }
    }
}

int Sum(int nowY, int nowX) {
    int ret = 0;
    for (int y = nowY; y >= 1; y -= (y & -y)) {
        for (int x = nowX; x >= 1; x -= (x & -x)) {
            ret += FenTree[y][x];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cin >> Table[y][x];
            Update(y, x, Table[y][x]);
        }
    }

    int w, r1, c1, r2, c2, num;
    while (M--) {
        cin >> w;

        if (w == 0) {
            cin >> r1 >> c1 >> num;
            Update(r1, c1, num - Table[r1][c1]);
            Table[r1][c1] = num;
        } else {
            cin >> r1 >> c1 >> r2 >> c2;

            printf("%d\n", Sum(r2, c2) - Sum(r2, c1 - 1) - Sum(r1 - 1, c2) + Sum(r1 - 1, c1 - 1));
        }
    }
    return 0;
}