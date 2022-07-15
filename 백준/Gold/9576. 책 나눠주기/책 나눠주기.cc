#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main() {
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;

        vector<pair<int, int>> vec;
        int max = 0;
        for (int m = 0; m < M; ++m) {
            int a, b;
            cin >> a >> b;

            vec.emplace_back(a, b);

            if (b > max)
                max = b;
        }

        sort(vec.begin(), vec.end(), cmp_pair);
        vector<bool> visited(max + 1, false);

        int cnt = 0;
        for (auto &i: vec) {
            for (int j = i.first; j <= i.second; ++j) {
                if (!visited[j]) {
                    visited[j] = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}