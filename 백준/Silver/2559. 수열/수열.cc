#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, PSum[100001], Ret = -1000000;

int main() {
    cin >> N >> K;

    for (int n = 1; n <= N; ++n) {
        int a;
        cin >> a;

        PSum[n] = PSum[n - 1] + a;
    }

    for (int i = K; i <= N; ++i)
        Ret = max(Ret, PSum[i] - PSum[i - K]);

    cout << Ret << endl;
    return 0;
}