#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> Table;

int get_power(vector<int> &t) {
    int ret = 0;
    for (int y = 0; y < t.size(); ++y) {
        int sum = 0;

        for (int x = 0; x < t.size(); ++x) {
            if (t[y] == t[x])
                continue;

            sum += Table[t[y]][t[x]];
        }

        ret += sum;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Table = vector<vector<int>>(N, vector<int>(N, 0));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> Table[y][x];
        }
    }

    int mn = INT32_MAX;
    for (int i = 0; i < (1 << N); ++i) {
        vector<int> t1, t2;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j))
                t1.push_back(j);
            else
                t2.push_back(j);
        }

        if (t1.size() != t2.size())
            continue;

        mn = min(mn, abs(get_power(t1) - get_power(t2)));
    }

    cout << mn << '\n';
    return 0;
}