#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define ll long long

using namespace std;

int Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> Q;

    ll ret = 0;
    unordered_map<string, priority_queue<int>> um;
    int cmd, k, b, n;
    string who;
    for (int q = 0; q < Q; ++q) {
        cin >> cmd >> who;

        if (cmd == 1) {
            cin >> k;

            auto iter = um.find(who);
            if (iter == um.end()) {
                priority_queue<int> pq;
                for (int i = 0; i < k; ++i) {
                    cin >> n;
                    pq.push(n);
                }

                um.insert(make_pair(who, pq));
            } else {
                for (int i = 0; i < k; ++i) {
                    cin >> n;
                    iter->second.push(n);
                }
            }
        } else {
            cin >> b;

            auto iter = um.find(who);
            if (iter == um.end())
                continue;

            int i = 0;
            while (!iter->second.empty() && i < b) {
                ret += iter->second.top();
                iter->second.pop();
                i++;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}