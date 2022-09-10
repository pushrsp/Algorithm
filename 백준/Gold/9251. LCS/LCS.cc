#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dp[1002][1002];

int main() {
    string a, b;
    cin >> a >> b;

    for (int i = a.length() - 1; i >= 0; --i) {
        for (int j = b.length() - 1; j >= 0; --j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}