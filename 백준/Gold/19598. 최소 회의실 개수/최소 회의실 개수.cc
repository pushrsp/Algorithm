#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n = 0; n < N; ++n) {
        pq.push(vec[n].second);

        if (!pq.empty() && vec[n].first >= pq.top())
            pq.pop();
    }

    cout << pq.size() << endl;
    return 0;
}