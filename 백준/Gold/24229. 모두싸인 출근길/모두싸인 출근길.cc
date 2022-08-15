#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<pair<int, int>> bridge(N);
    for (int n = 0; n < N; ++n)
        cin >> bridge[n].first >> bridge[n].second;

    sort(bridge.begin(), bridge.end());

    vector<pair<int, int>> vec;
    int left = bridge[0].first, right = bridge[0].second;
    for (int n = 1; n < N; ++n) {
        if (right >= bridge[n].first) {
            right = max(right, bridge[n].second);
        } else {
            vec.emplace_back(left, right);
            left = bridge[n].first, right = bridge[n].second;
        }
    }

    vec.emplace_back(left, right);

    int pivot = 0;
    int idx = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (pivot >= vec[i].first) {
            idx = i;
            pivot = max(pivot, vec[i].second + (vec[i].second - vec[i].first));
        }
    }

    cout << vec[idx].second << endl;

    return 0;
}