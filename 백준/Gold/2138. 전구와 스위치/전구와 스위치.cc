#include <iostream>
#include <vector>
#include <cmath>

#define MAX 99999

using namespace std;

int N, ANSWER = MAX;
string source, dest, temp;

void turn_on(int idx) {
    if (idx > 0)
        temp[idx - 1] = temp[idx - 1] == '1' ? '0' : '1';

    temp[idx] = temp[idx] == '1' ? '0' : '1';

    if (idx < N - 1)
        temp[idx + 1] = temp[idx + 1] == '1' ? '0' : '1';
}

void solve(bool turn) {
    temp = source;

    int cnt = 0;
    if (turn) {
        temp[0] = temp[0] == '1' ? '0' : '1';
        temp[1] = temp[1] == '1' ? '0' : '1';
        cnt++;
    }

    for (int i = 1; i < N; ++i) {
        if (temp[i - 1] != dest[i - 1]) {
            turn_on(i);
            cnt++;
        }
    }

    if (temp == dest)
        ANSWER = min(ANSWER, cnt);
}

int main() {
    cin >> N;
    cin >> source;
    cin >> dest;

    solve(true);
    solve(false);

    if (ANSWER != MAX)
        cout << ANSWER << endl;
    else
        cout << -1 << endl;
    return 0;
}