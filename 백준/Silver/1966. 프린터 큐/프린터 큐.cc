#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int T;

int main() {
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;

        priority_queue<int, vector<int>, less<int>> pq;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            q.push({i, k});
            pq.push(k);
        }

        int cnt = 1;
        while (!q.empty()) {
            int nowIdx = q.front().first;
            int nowVal = q.front().second;
            q.pop();

            if (pq.top() == nowVal) {
                pq.pop();
                if (nowIdx == m) {
                    cout << cnt << endl;
                    break;
                }
                cnt++;
            } else {
                q.push({nowIdx, nowVal});
            }
        }
    }
    return 0;
}