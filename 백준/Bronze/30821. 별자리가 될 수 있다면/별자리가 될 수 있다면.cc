#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, Ret;

void go(int n, int idx) {
    if (n == 5) {
        Ret += 1;
        return;
    }

    for (int i = idx; i < N; ++i)
        go(n + 1, i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    go(0, 0);

    cout << Ret << '\n';

    return 0;
}