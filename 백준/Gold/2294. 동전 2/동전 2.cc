#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 987654321

using namespace std;

int N, K, Dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<int> nums(N);
    for (int n = 0; n < N; ++n)
        cin >> nums[n];

    fill(Dp, Dp + 10001, MAX);
    Dp[0] = 0;
    for (int i = 0; i < K; ++i) {
        if (Dp[i] == MAX)
            continue;

        for (int &num: nums) {
            if (i + num <= K)
                Dp[i + num] = min(Dp[i + num], Dp[i] + 1);
        }
    }

    if (Dp[K] == MAX)
        cout << -1 << '\n';
    else
        cout << Dp[K] << '\n';
    
    return 0;
}