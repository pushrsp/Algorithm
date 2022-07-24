#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    cin >> N;

    vector<pair<int, int>> hw(N);
    for (int n = 0; n < N; ++n) {
        cin >> hw[n].first >> hw[n].second;
    }

    sort(hw.begin(), hw.end(), cmp_pair);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n = 0; n < N; ++n) {
        auto cur = hw[n];
        pq.push(cur.second);

        if (cur.first < pq.size())
            pq.pop();
    }

    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << endl;
    return 0;
}