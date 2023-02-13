#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int a;
    vector<pair<int, int>> vec;

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= M; ++x) {
            cin >> a;
            vec.emplace_back(a, y);
        }
    }

    sort(vec.begin(), vec.end());

    unordered_map<int, int> um;
    int len = N * M;
    int ret = INF, left = 0, right = 0;

    while (right < vec.size()) {
        if (um.size() == N) {
            if (vec[right - 1].second != vec[left].second)
                ret = min(ret, vec[right - 1].first - vec[left].first);

            auto iter = um.find(vec[left].second);

            iter->second -= 1;
            if (iter->second == 0)
                um.erase(vec[left].second);

            left++;
        } else {
            if (um.count(vec[right].second) == 0)
                um.insert(make_pair(vec[right].second, 1));
            else
                um.find(vec[right].second)->second += 1;

            right++;
        }
    }

    cout << ret << '\n';

    return 0;
}