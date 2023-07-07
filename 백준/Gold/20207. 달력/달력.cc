#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, C[366];

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; ++i)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end(), cmp_pair);

    for (auto &p: vec)
        C[p.first] += 1, C[p.second + 1] -= 1;
    for (int i = 1; i <= 365; ++i)
        C[i] += C[i - 1];

    int ret = 0, height = 0, width = 0;
    for (int i = 1; i <= 365; ++i) {
        if (C[i] == 0) {
            ret += width * height;
            width = 0, height = 0;
        } else {
            height = max(height, C[i]);
            width++;
        }
    }

    ret += width * height;

    cout << ret << '\n';

    return 0;
}