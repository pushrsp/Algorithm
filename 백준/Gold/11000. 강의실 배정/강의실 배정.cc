#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> classes;

    for (int i = 0; i < N; ++i) {
        int s, t;
        cin >> s >> t;

        classes.emplace_back(s, t);
    }

    sort(classes.begin(), classes.end());

    pq.push(classes[0].second);
    for (int i = 1; i < N; ++i) {
        pq.push(classes[i].second);
        if (classes[i].first >= pq.top()) {
            pq.pop();
        }
    }

    cout << pq.size() << endl;
    return 0;
}