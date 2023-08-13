#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int level;
    for (int i = 0; i < N; ++i) {
        cin >> level;

        if (level >= 300) {
            cout << 1 << ' ';
        } else if (275 <= level && level < 300) {
            cout << 2 << ' ';
        } else if (250 <= level && level < 275) {
            cout << 3 << ' ';
        } else {
            cout << 4 << ' ';
        }
    }
    return 0;
}