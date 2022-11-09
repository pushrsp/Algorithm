#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K, Dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<int> nums(N);
    Dp[0] = 1;

    for (int n = 0; n < N; ++n)
        cin >> nums[n];

    for (int &num: nums) {
        for (int i = num; i <= K; ++i)
            Dp[i] += Dp[i - num];
    }

    cout << Dp[K] << '\n';

    return 0;
}