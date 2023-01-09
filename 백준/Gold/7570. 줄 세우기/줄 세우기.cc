#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

int N, DP[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int a, ret = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        DP[a] = DP[a - 1] + 1;
        ret = max(ret, DP[a]);
    }

    cout << N - ret << '\n';
    return 0;
}