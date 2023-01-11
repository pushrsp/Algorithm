#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> fuel(N + 1);
    for (int i = 0; i < N; ++i)
        cin >> fuel[i].first >> fuel[i].second;

    int p;
    cin >> fuel[N].first >> p;

    sort(fuel.begin(), fuel.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    int ret = 0;
    for (int i = 0; i <= N; ++i) {
        while (fuel[i].first > p) {
            if (pq.empty()) {
                cout << -1 << '\n';
                return 0;
            }

            p += pq.top().first;
            pq.pop();
            ret += 1;
        }

        pq.emplace(fuel[i].second, fuel[i].first);
    }

    cout << ret << '\n';

    return 0;
}