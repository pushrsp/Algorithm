#include <iostream>
#include <queue>
#include <cmath>

#define MAX 100001
#define ll long long

using namespace std;

ll N, K, Arr[MAX], DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    int left = 1, right = 1;
    ll sum = Arr[left];
    while (left <= N && right <= N) {
        DP[right] = max(DP[right], DP[right - 1]);

        if (sum >= K) {
            DP[right] = max(DP[right], DP[left - 1] + sum - K);
            if (left < right) {
                sum -= Arr[left];
                left++;
            } else if (left == right) {
                left++, right++;
                sum = Arr[left];
            }
        } else {
            right++;
            sum += Arr[right];
        }
    }

    cout << DP[N] << '\n';
    return 0;
}