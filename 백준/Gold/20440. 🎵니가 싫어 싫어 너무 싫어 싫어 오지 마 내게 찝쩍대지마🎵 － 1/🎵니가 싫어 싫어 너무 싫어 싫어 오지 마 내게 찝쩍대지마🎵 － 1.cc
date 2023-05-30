#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

#define MAX 10000001

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    set<int> ss;
    vector<int> temp;
    vector<pair<int, int>> pos(N);

    for (int i = 0; i < N; ++i) {
        cin >> pos[i].first >> pos[i].second;

        temp.push_back(pos[i].first);
        temp.push_back(pos[i].second);
    }

    sort(temp.begin(), temp.end());

    unordered_map<int, int> idx_to_num, num_to_idx;
    int i = 0;
    for (i = 0; i < temp.size(); ++i) {
        if (num_to_idx.find(temp[i]) == num_to_idx.end()) {
            num_to_idx.insert(make_pair(temp[i], i));
            idx_to_num.insert(make_pair(i, temp[i]));
        }
    }

    vector<int> dp(i);
    for (auto &p: pos) {
        dp[num_to_idx[p.first]]++;
        dp[num_to_idx[p.second]]--;
    }

    for (int j = 1; j < dp.size(); ++j)
        dp[j] += dp[j - 1];

    int ret = 0;
    for (int &d: dp)
        ret = max(ret, d);

    cout << ret << '\n';

    int left = -1, right = -1;
    for (int j = 0; j < dp.size(); ++j) {
        if (dp[j] == ret) {
            if (left == -1)
                left = j;
        } else if (dp[j] != ret && left != -1) {
            right = j;
            break;
        }
    }

    cout << idx_to_num[left] << ' ' << idx_to_num[right] << '\n';
    return 0;
}