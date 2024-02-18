#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

int N, T, K, S, E, A[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    for (int n = 0; n < N; ++n) {
        cin >> K;

        for (int k = 0; k < K; ++k) {
            cin >> S >> E;

            for (int i = S; i <= E - 1; ++i)
                A[n][i] = 1;
        }
    }

    int ret = -1, t1, t2;
    for (int t = 0; t <= 1000 - T; ++t) {
        int s = t, e = t + T, score = 0;

        for (int n = 0; n < N; ++n) {
            for (int i = s; i <= e - 1; ++i) {
                if (A[n][i] > 0)
                    score += 1;
            }
        }

        if (score > ret) {
            ret = score;
            t1 = s, t2 = e;
        }
    }

    cout << t1 << ' ' << t2 << '\n';

    return 0;
}