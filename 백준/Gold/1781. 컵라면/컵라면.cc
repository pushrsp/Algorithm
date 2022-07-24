#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        int cur = vec[i].first;
        pq.push(vec[i].second);
        while (cur < pq.size())
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