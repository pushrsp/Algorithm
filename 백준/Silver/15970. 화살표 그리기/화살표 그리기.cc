#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define INF 987654321

using namespace std;

int N;
vector<int> Colors[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int x, y;
    for (int i = 1; i <= N; ++i) {
        cin >> x >> y;
        Colors[y].push_back(x);
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        if (Colors[i].empty())
            continue;

        sort(Colors[i].begin(), Colors[i].end());
        for (int j = 0; j < Colors[i].size(); ++j) {
            int left = ::abs(Colors[i][j] - Colors[i][max(0, j - 1)]);
            if (left == 0)
                left = INF;

            int right = ::abs(Colors[i][j] - Colors[i][min(static_cast<int>(Colors[i].size()) - 1, j + 1)]);
            if (right == 0)
                right = INF;

            ret += min(left, right);
        }
    }

    cout << ret << '\n';
    return 0;
}