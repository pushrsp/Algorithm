#include <iostream>
#include <cstring>
#include <vector>

#define INF 1e18
#define ll long long

using namespace std;

ll D, S, A[106], C[106], P[106], DP[106];
vector<int> Nodes;

ll go(int curr) {
    if (curr >= S + 1)
        return 0;

    ll &ret = DP[curr];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = curr + 1; i <= S + 1; ++i) {
        if (P[i] - P[curr] <= D)
            ret = min(ret, go(i) + C[i]);
    }

    return ret;
}

void trace(int curr) {
    if (curr >= S + 1)
        return;

    for (int i = curr + 1; i <= S + 1; ++i) {
        if (DP[curr] - DP[i] == C[i]) {
            if (i != S + 1)
                Nodes.push_back(i);

            trace(i);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> D;

    cin >> S;

    for (int s = 1; s <= S + 1; ++s) {
        cin >> A[s];
        P[s] = P[s - 1] + A[s];
    }

    for (int s = 1; s <= S; ++s)
        cin >> C[s];

    ::memset(DP, -1, sizeof(DP));

    ll ret = go(0);

    if (ret >= INF) {
        cout << 0 << '\n';
    } else {
        cout << ret << '\n';
        trace(0);

        cout << Nodes.size() << '\n';
        for (auto &node: Nodes)
            cout << node << ' ';

        cout << '\n';
    }

    return 0;
}