#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, Arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    for (int n = 0; n < N; ++n)
        cin >> Arr[n];

    sort(Arr, Arr + N, greater<int>());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < min(N, M); ++i)
        pq.push(0);

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        int sum = pq.top() + Arr[i];
        pq.pop();
        pq.push(sum);

        ret = max(ret, sum);
    }

    cout << ret << '\n';

    return 0;
}