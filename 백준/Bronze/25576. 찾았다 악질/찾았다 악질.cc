#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<int> vec(M);
    for (int m = 0; m < M; ++m)
        cin >> vec[m];

    int ret = 0, num;
    for (int n = 0; n < N - 1; ++n) {
        int sum = 0;
        for (int m = 0; m < M; ++m) {
            cin >> num;
            sum += abs(vec[m] - num);
        }

        if (sum > 2000)
            ret += 1;
    }

    if (ret * 2 >= N - 1)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}