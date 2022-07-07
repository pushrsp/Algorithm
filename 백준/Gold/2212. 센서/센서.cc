#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, K;
vector<int> sensors;
vector<int> dist;

int main() {
    cin >> N >> K;

    sensors = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> sensors[i];

    sort(sensors.begin(), sensors.end());

    for (int i = 0; i < sensors.size() - 1; ++i) {
        int from = sensors[i];
        int to = sensors[i + 1];

        dist.push_back(abs(from - to));
    }

    sort(dist.begin(), dist.end(), greater<int>());

    int sum = 0;
    for (int i = K - 1; i < dist.size(); ++i) {
        sum += dist[i];
    }

    cout << sum << endl;

    return 0;
}