#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string n, m;
        cin >> n >> m;

        if (n == "0" && m == "0.00")
            break;

        fill(dp, dp + 10001, -1);
        int nn = stoi(n);
        int mm = static_cast<int>(stod(m) * 100 + 0.5);
        vector<pair<int, int>> vec;
        for (int i = 0; i < nn; ++i) {
            string c, p;
            cin >> c >> p;

            vec.emplace_back(stoi(c), static_cast<int>(stod(p) * 100 + 0.5));
        }

        dp[0] = 0;
        int answer = 0;
        for (int i = 0; i < mm; ++i) {
            if (dp[i] == -1)
                continue;

            for (auto &candy: vec) {
                if (i + candy.second <= mm) {
                    if (dp[i + candy.second] == -1) {
                        dp[i + candy.second] = dp[i] + candy.first;
                        answer = max(answer, dp[i] + candy.first);
                    } else {
                        dp[i + candy.second] = max(dp[i + candy.second], dp[i] + candy.first);
                        answer = max(answer, dp[i + candy.second]);
                    }
                }
            }
        }

        cout << answer << '\n';
    }
    return 0;
}