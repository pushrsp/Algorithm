#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>

using namespace std;

int N, M, Arr[301][21], DP[301][21], Trace[301][21];

int go(int n, int m) {
    if (m > M)
        return 0;

    int &ret = DP[n][m];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i <= n; ++i) {
        int temp = go(n - i, m + 1) + Arr[i][m];

        if (temp > ret) {
            ret = temp;
            Trace[n][m] = i;
        }
    }

    return ret;
}

void print() {
    int temp = N;
    for (int i = 1; i <= M; ++i) {
        cout << Trace[temp][i] << ' ';
        temp -= Trace[temp][i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int invest;
    for (int i = 0; i < N; ++i) {
        cin >> invest;
        for (int j = 1; j <= M; ++j)
            cin >> Arr[invest][j];
    }

    ::memset(DP, -1, sizeof(DP));

    cout << go(N, 1) << '\n';
    print();
    return 0;
}