#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100001

using namespace std;

int N, Arr[MAX], DP[2][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    for (int i = 1; i <= N; ++i) {
        if (Arr[i] == 1)
            DP[0][i] = max(DP[0][i - 1] + 1, 1);
        else
            DP[0][i] = max(DP[0][i - 1] - 1, 0);
    }

    for (int i = 1; i <= N; ++i) {
        if (Arr[i] == 2)
            DP[1][i] = max(DP[1][i - 1] + 1, 1);
        else
            DP[1][i] = max(DP[1][i - 1] - 1, 0);
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i)
        ret = max(ret, max(DP[0][i], DP[1][i]));

    cout << ret << '\n';
    
    return 0;
}