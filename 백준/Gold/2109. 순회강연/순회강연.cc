#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    cin >> N;

    vector<pair<int, int>> lecture(N);
    for (int n = 0; n < N; ++n)
        cin >> lecture[n].first >> lecture[n].second;

    sort(lecture.begin(), lecture.end(), cmp_pair);

    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n = 0; n < N; ++n) {
        sum += lecture[n].first;
        pq.push(lecture[n].first);

        while (lecture[n].second < pq.size()) {
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << sum << endl;

    return 0;
}