#include <iostream>
#include <vector>

using namespace std;
vector<string> now, desired;

int N, M;

void flip(int _y, int _x) {
    for (int y = _y; y < _y + 3; ++y) {
        for (int x = _x; x < _x + 3; ++x) {
            now[y][x] = now[y][x] == '0' ? '1' : '0';
        }
    }
}

int main() {
    cin >> N >> M;

    now = vector<string>(N);
    desired = vector<string>(N);

    for (int n = 0; n < N; ++n)
        cin >> now[n];


    for (int n = 0; n < N; ++n)
        cin >> desired[n];

    int cnt = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < now[y].size(); ++x) {
            if (y >= N - 2 || x >= M - 2) {
                if (now[y][x] != desired[y][x]) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    continue;
                }
            }

            if (now[y][x] != desired[y][x]) {
                flip(y, x);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}