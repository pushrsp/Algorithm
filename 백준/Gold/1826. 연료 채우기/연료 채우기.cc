#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, P;
vector<pair<int, int>> Stations;

vector<int> get_best(int p, int idx) {
    vector<int> ret = {-1, -1, -1};
    for (int i = idx; i < N + 1; ++i) {
        if (Stations[i].first <= p && ret[1] < Stations[i].second) {
            ret[0] = Stations[i].first;
            ret[1] = Stations[i].second;
            ret[2] = i;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Stations = vector<pair<int, int>>(N);
    for (int n = 0; n < N; ++n)
        cin >> Stations[n].first >> Stations[n].second;

    cin >> L >> P;

    sort(Stations.begin(), Stations.end());

    int idx = 0, cnt = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    while (L > P) {
        while (idx < N && Stations[idx].first <= P) {
            pq.push(Stations[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            P += pq.top();
            pq.pop();
            cnt++;
        } else {
            break;
        }
    }

    if (P >= L)
        cout << cnt << '\n';
    else
        cout << -1 << '\n';

    return 0;
}