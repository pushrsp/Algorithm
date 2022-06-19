#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    struct compare {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        }
    };

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for (int j = 0; j < n; ++j) {
            int o, p;
            cin >> o >> p;
            pq.push({o, p});
        }

        pair<int, int> c = pq.top();
        pq.pop();
        int cnt = 1;

        while (!pq.empty()) {
            if (c.second > pq.top().second) {
                c = pq.top();
                cnt++;
            }

            pq.pop();
        }

        cout << cnt << endl;
    }
    return 0;
}