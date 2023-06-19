#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int H, N, DP[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> H >> N;

    vector<pair<int, int>> vec(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> vec[i].first >> vec[i].second;

    ::memset(DP, -1, sizeof(DP));

    DP[0] = 987654321;
    for (int n = 1; n <= N; ++n) {
        int height = vec[n].first, speed = vec[n].second;

        for (int h = H; h >= height; --h) {
            if (DP[h - height] != -1)
                DP[h] = max(DP[h], min(DP[h - height], speed));
        }
    }

    cout << DP[H] << '\n';

    return 0;
}