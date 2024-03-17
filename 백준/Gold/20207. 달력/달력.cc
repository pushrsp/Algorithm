#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define INF 987654321

using namespace std;

int N, A[367];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int s, e;
    for (int n = 0; n < N; ++n) {
        cin >> s >> e;
        A[s]++, A[e + 1]--;
    }

    for (int i = 1; i <= 366; ++i)
        A[i] += A[i - 1];

    int ret = 0;
    for (int i = 1; i <= 365; ++i) {
        if (A[i] == 0)
            continue;

        int j = i + 1, h = 1;
        for (j; j <= 365; ++j) {
            if (A[j] == 0)
                break;

            h = max(h, A[j]);
        }

        ret += (j - i) * (h);
        i = j - 1;
    }

    cout << ret << '\n';

    return 0;
}