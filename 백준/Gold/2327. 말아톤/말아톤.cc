#include <iostream>
#include <vector>
#include <cstring>

#define INF 987654321

using namespace std;

int N, H, DP[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> H >> N;

    DP[0] = INF;
    int h, s;
    for (int n = 1; n <= N; ++n) {
        cin >> h >> s;

        for (int i = H; i >= h; --i) {
            if (DP[i - h] > 0)
                DP[i] = max(DP[i], min(DP[i - h], s));
        }
    }

    cout << DP[H] << '\n';

    return 0;
}