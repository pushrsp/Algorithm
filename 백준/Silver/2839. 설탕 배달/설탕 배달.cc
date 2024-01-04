#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    int cnt = 0;
    bool done = true;
    while (N > 0) {
        if (N / 5 == 0 && N / 3 == 0) {
            done = false;
            break;
        }

        if (N % 5 < N % 3) {
            N -= 5;
        } else if (N % 5 > N % 3) {
            N -= 3;
        } else {
            if (N / 5 < N / 3)
                N -= 5;
            else
                N -= 3;
        }
        cnt++;
    }

    if (done) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}