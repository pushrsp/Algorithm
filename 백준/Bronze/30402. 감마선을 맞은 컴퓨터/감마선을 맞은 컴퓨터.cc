#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<vector<char>> m(15, vector<char>(15));
    for (int y = 0; y < 15; ++y) {
        for (int x = 0; x < 15; ++x)
            cin >> m[y][x];
    }

    for (int y = 0; y < 15; ++y) {
        for (int x = 0; x < 15; ++x) {
            if (m[y][x] == 'r' || m[y][x] == 'o' || m[y][x] == 'y' || m[y][x] == 'p')
                continue;

            if (m[y][x] == 'w') {
                cout << "chunbae" << '\n';
                return 0;
            } else if (m[y][x] == 'b') {
                cout << "nabi" << '\n';
                return 0;
            } else {
                cout << "yeongcheol" << '\n';
                return 0;
            }
        }
    }

    return 0;
}