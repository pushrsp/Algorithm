#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

#define ll long long

using namespace std;

int A, B;

void go(int a, int b, int t) {
    if (a >= 5 || b >= 5) {
        if (t % 2)
            cout << "yt" << '\n';
        else
            cout << "yj" << '\n';

        ::exit(0);
    }

    if (t % 2)
        go(a + b, b, t + 1);
    else
        go(a, b + a, t + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;

    go(A, B, 0);

    return 0;
}