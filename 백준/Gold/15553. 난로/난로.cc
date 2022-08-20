#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll N, K;

int main() {
    cin >> N >> K;

    vector<ll> friends(N);
    for (int n = 0; n < N; ++n)
        cin >> friends[n];

    vector<ll> diff;
    ll start = friends[0], end = friends[0] + 1, cnt = 1;
    for (int n = 1; n < N; ++n) {
        if (end != friends[n]) {
            cnt++;
            diff.push_back(friends[n] - end);
            start = friends[n];
            end = friends[n] + 1;
        } else {
            end = friends[n] + 1;
        }
    }

    sort(diff.begin(), diff.end());
    if (K < cnt) {
        for (int i = 0; i < cnt - K; ++i)
            N += diff[i];
    }

    cout << N << endl;

    return 0;
}