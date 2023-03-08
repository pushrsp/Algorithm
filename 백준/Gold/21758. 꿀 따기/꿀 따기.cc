#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define MAX 100001

using namespace std;

int N;
ll Arr[MAX], DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> Arr[i];
        DP[i + 1] = DP[i] + Arr[i];
    }

    ll ret = 0, left, right;
    for (int i = 2; i < N; ++i) {
        left = DP[i - 1] - DP[1];
        right = DP[N] - DP[i];

        ret = max(ret, left + right * 2);
    }

    for (int i = N - 1; i >= 2; --i) {
        left = DP[i - 1];
        right = DP[N - 1] - DP[i];

        ret = max(ret, left * 2 + right);
    }

    for (int i = 2; i < N; ++i) {
        left = DP[i] - DP[1];
        right = DP[N - 1] - DP[i - 1];

        ret = max(ret, left + right);
    }

    cout << ret << '\n';
    return 0;
}