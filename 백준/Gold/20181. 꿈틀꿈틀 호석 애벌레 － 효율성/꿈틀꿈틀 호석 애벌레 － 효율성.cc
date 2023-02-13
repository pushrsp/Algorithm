#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define ll long long

using namespace std;

int N, Arr[MAX];
ll K;
ll DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    int left = 0, right = 1;
    ll sum = 0;

    while (left <= N && right <= N) {
        sum += Arr[right];
        DP[right] = DP[right - 1];

        while (sum >= K) {
            DP[right] = max(DP[right], DP[left] + sum - K);
            sum -= Arr[++left];
        }
        right++;
    }

    cout << DP[N] << '\n';
    return 0;
}