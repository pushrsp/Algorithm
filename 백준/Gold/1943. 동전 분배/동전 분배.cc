#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, DP[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<pair<int, int>> vec;
    for (int i = 0; i < 3; ++i) {
        cin >> N;

        ::memset(DP, 0, sizeof(DP));
        DP[0] = 1;
        vec = vector<pair<int, int>>(N + 1);
        int sum = 0;
        for (int j = 1; j <= N; ++j) {
            cin >> vec[j].first >> vec[j].second;
            sum += vec[j].first * vec[j].second;
        }

        if (sum % 2) {
            cout << 0 << '\n';
            continue;
        }

        for (int n = 1; n <= N; ++n) {
            int coin = vec[n].first, amount = vec[n].second;

            for (int s = 50000; s >= 0; --s) {
                if (coin <= s) {
                    if (DP[s - coin] > 0) {
                        for (int a = 0; a < amount; ++a) {
                            if (s + coin * a <= 50000)
                                DP[s + coin * a] = 1;
                        }
                    }
                }
            }
        }

        if (DP[sum / 2])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}