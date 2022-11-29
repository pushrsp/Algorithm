#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 10007;
int N, DP[1001];

int go(int n) {
    if (n <= 1)
        return 1;

    int &ret = DP[n];
    if (ret)
        return ret;

    return ret = ((go(n - 1) % MOD) + (go(n - 2) % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cout << go(N) << '\n';
    return 0;
}