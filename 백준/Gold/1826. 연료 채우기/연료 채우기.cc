#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, L, P;

int main() {
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int n = 0; n < N; ++n)
        cin >> vec[n].first >> vec[n].second;

    cin >> L >> P;

    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, less<int>> pq;

    int cnt = 0;
    int idx = 0;
    while (L > P) {
        while (vec[idx].first <= P && idx < N) {
            pq.push(vec[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            P += pq.top();
            pq.pop();
            cnt++;
        } else {
            if (idx == N || vec[idx].first > P) {
                cnt = -1;
                break;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}