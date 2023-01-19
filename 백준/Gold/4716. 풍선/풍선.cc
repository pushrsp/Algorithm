#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

typedef pair<int, int> pii;

int N, A, B;
int want[1000];
int distA[1000];
int distB[1000];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while (1) {
        priority_queue<pii> pq;
        int ans = 0;
        cin >> N >> A >> B;
        if (N == 0 && A == 0 && B == 0)
            break;

        rep(i, N) {
            cin >> want[i] >> distA[i] >> distB[i];
            pq.emplace(abs(distA[i] - distB[i]), i);
        }
        while (!pq.empty()) {
            auto [gap, here] = pq.top();
            pq.pop();
            // cout << "here: " << here << '\n';
            int& getfrom = (distA[here] > distB[here] ? B : A);
            // cout << "getfrom: " << getfrom << '\n';
            if (getfrom) {
                int cnt = min(getfrom, want[here]);
                getfrom -= cnt;
                want[here] -= cnt;
                ans += cnt * min(distA[here], distB[here]);
            }
            ans += max(distA[here], distB[here]) * want[here];
        }
        cout << ans << '\n';
    }
    return 0;
}