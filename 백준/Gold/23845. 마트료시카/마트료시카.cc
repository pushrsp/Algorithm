#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define MAX 200001

using namespace std;

int N;
priority_queue<ll> pqs[100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<ll> x(N);
    for (int i = 0; i < N; ++i)
        cin >> x[i];

    sort(x.begin(), x.end(), greater<int>());

    for (int n = 0; n < N; ++n) {
        if (pqs[x[n] + 1].empty()) {
            pqs[x[n]].push(x[n]);
        } else {
            int top = pqs[x[n] + 1].top();
            pqs[x[n] + 1].pop();
            pqs[x[n]].push(top);
        }
    }

    ll ret = 0;
    for (int i = 1; i <= 100000; ++i) {
        while (!pqs[i].empty()) {
            ll top = pqs[i].top();
            pqs[i].pop();
            ret += top * (top - i + 1);
        }
    }

    cout << ret << '\n';

    return 0;
}