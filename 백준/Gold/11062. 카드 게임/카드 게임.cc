#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, N, Arr[1001], DP[1001][1001];

int go(int left, int right, int who) {
    if (left > right)
        return 0;

    int &ret = DP[left][right];
    if (ret != -1)
        return ret;

    ret = INT32_MAX;

    if (who % 2)
        return ret = max(go(left + 1, right, who + 1) + Arr[left],
                         go(left, right - 1, who + 1) + Arr[right]);
    else
        return ret = min(go(left + 1, right, who + 1),
                         go(left, right - 1, who + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        ::memset(DP, -1, sizeof(DP));
        ::memset(Arr, 0, sizeof(Arr));
        
        for (int n = 1; n <= N; ++n)
            cin >> Arr[n];

        cout << go(1, N, 1) << '\n';
    }
    return 0;
}