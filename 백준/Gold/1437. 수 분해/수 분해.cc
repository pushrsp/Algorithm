#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 10007;
int N, DP[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    if (N <= 4) {
        cout << N << '\n';
        return 0;
    }

    vector<int> temp;
    for (int i = 0; i < N / 3; ++i)
        temp.push_back(3);

    if (N % 3) {
        if (N % 3 == 2)
            temp.push_back(2);
        else
            temp.back() += 1;
    }

    int ret = 1;
    for (auto &t: temp) {
        ret *= t;
        ret %= MOD;
    }

    cout << ret << '\n';
    return 0;
}