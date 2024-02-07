#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define ll long long

using namespace std;

int N, M, A[2][4], Ret;

void go(int n, int p, int sum) {
    if (n >= N) {
        if (sum >= M)
            Ret += 1;

        return;
    }

    for (int i = 0; i < 2; ++i) {
        for (int k = 1; k <= 3; ++k) {
            if (p == k)
                go(n + 1, k, sum + (A[i][k] / 2));
            else
                go(n + 1, k, sum + A[i][k]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    cin >> A[0][1] >> A[0][2] >> A[0][3];
    cin >> A[1][1] >> A[1][2] >> A[1][3];

    go(0, 0, 0);

    cout << Ret << '\n';

    return 0;
}