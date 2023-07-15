#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, X, Arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> X;
    for (int n = 1; n <= N; ++n)
        cin >> Arr[n];

    int left = 1, right = N * 2, mid, ret = INT32_MAX;
    while (left <= right) {
        mid = (left + right) / 2;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= mid; ++i)
            pq.push(0);

        for (int n = 1; n <= N; ++n) {
            int curr = pq.top();
            pq.pop();
            pq.push(curr + Arr[n]);
        }

        int mx = 0;
        while (!pq.empty()) {
            mx = max(mx, pq.top());
            pq.pop();
        }

        if (mx <= X) {
            right = mid - 1;
            ret = min(ret, mid);
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}