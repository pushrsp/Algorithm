#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n = 0; n < N; ++n) {
        pq.push(vec[n].second);

        if (pq.size() > vec[n].first) {
            pq.pop();
        }
    }

    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << '\n';
    return 0;
}