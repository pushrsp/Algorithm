#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> L;

    vector<pair<string, int>> vec(N);
    int ret = 0;
    for (int n = 0; n < N; ++n) {
        cin >> vec[n].first;

        string temp;
        int cnt = 0;
        for (int l = 0; l < L; ++l) {
            if (vec[n].first[l] == '1') {
                temp.push_back(vec[n].first[l]);
            } else {
                if (!temp.empty())
                    cnt += 1;

                temp.clear();
            }
        }

        if (!temp.empty())
            cnt += 1;

        vec[n].second = cnt;
        ret = max(ret, cnt);
    }

    int cnt = 0;
    for (auto &p: vec) {
        if (p.second == ret)
            cnt += 1;
    }

    cout << ret << ' ' << cnt << '\n';

    return 0;
}