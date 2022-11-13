#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, DP[100001];
vector<pair<int, int>> Vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    Vec = vector<pair<int, int>>(N);
    for (int n = 0; n < N; ++n)
        cin >> Vec[n].first >> Vec[n].second;

    for (auto &vec: Vec) {
        for (int i = K; i >= vec.first; --i)
            DP[i] = max(DP[i], DP[i - vec.first] + vec.second);
    }

    cout << DP[K] << '\n';
    return 0;
}