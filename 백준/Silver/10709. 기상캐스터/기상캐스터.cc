#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, H;
vector<vector<int>> Map;

int main() {
    cin >> N >> H;

    Map = vector<vector<int>>(N, vector<int>(H, -1));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < H; ++x) {
            char c;
            cin >> c;

            if (c == 'c')
                Map[y][x] = 0;
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < H; ++x) {
            if (Map[y][x] == 0) {
                int nowX = x;
                int start = 1;
                for (int i = nowX + 1; i < H; ++i) {
                    if (Map[y][i] == -1)
                        Map[y][i] = start++;
                    else
                        break;
                }
            }
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < H; ++x) {
            cout << Map[y][x] << " ";
        }
        cout << endl;
    }
    return 0;
}