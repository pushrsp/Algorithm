#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long
#define MAX 1000001

using namespace std;

int C, D, N;
ll DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> C;
    while (C--) {
        cin >> D >> N;

        ll sum = 0;
        int num;

        for (int i = 0; i < N; ++i) {
            cin >> num;
            sum += num;

            DP[sum % D]++;
        }

        ll ret = DP[0];
        for (int i = 0; i < D; ++i)
            ret += DP[i] * (DP[i] - 1) / 2;

        cout << ret << '\n';
        ::memset(DP, 0, sizeof(DP));
    }
    return 0;
}