#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001

using namespace std;

int N, M, Rooms[MAX];

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> M;

    if (M == 0) {
        cout << N << '\n';
        return 0;
    }

    vector<pair<int, int>> vec(M);
    for (int i = 0; i < M; ++i)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end(), cmp_pair);

    int ret = N;
    int start = vec[0].first, end = vec[0].second;

    for (int i = 1; i < M; ++i) {
        if (end >= vec[i].first) {
            end = max(end, vec[i].second);
        } else {
            ret -= end - start;
            start = vec[i].first, end = vec[i].second;
        }
    }

    ret -= end - start;

    cout << ret << '\n';

    return 0;
}