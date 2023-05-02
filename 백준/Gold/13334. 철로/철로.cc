#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, D;
vector<pair<int, int>> Lines;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    Lines = vector<pair<int, int>>(N);

    int n1, n2;
    for (int i = 0; i < N; ++i) {
        cin >> n1 >> n2;
        Lines[i].first = min(n1, n2);
        Lines[i].second = max(n1, n2);
    }

    cin >> D;

    sort(Lines.begin(), Lines.end(), cmp_pair);

    int ret = 0;
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        if (Lines[i].second - Lines[i].first <= D)
            pq.push(-Lines[i].first);
        else
            continue;

        while (!pq.empty()) {
            if (-pq.top() < Lines[i].second - D) {
                pq.pop();
            } else {
                ret = max(ret, static_cast<int>(pq.size()));
                break;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}