#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<pair<int, int>> j(N);
    vector<int> b(K);

    for (int n = 0; n < N; ++n)
        cin >> j[n].first >> j[n].second;

    for (int k = 0; k < K; ++k)
        cin >> b[k];

    sort(j.begin(), j.end());
    sort(b.begin(), b.end());

    ll answer = 0;
    int idx = 0;

    priority_queue<int> pq;
    for (int k = 0; k < K; ++k) {

        for (int i = idx; i < N; ++i) {
            if (j[i].first > b[k])
                break;

            pq.push(j[i].second);
            idx++;
        }

        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';
    return 0;
}