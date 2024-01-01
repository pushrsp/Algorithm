#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N;
bool Seats[10][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s;
    for (int n = 0; n < N; ++n) {
        cin >> s;

        int y = s[0] - 'A';
        int x = stoi(s.substr(1));

        Seats[y][x - 1] = true;
    }

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 20; ++x) {
            if (Seats[y][x])
                cout << 'o';
            else
                cout << '.';
        }
        cout << '\n';
    }
    return 0;
}