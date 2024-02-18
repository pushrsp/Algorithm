#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    cin >> N;

    int mx = 0;
    vector<pair<int, string>> a(N);
    for (int n = 0; n < N; ++n) {
        cin >> a[n].second;

        int year = 0;
        for (int i = 0; i < 4; ++i) {
            int t = (s[i] - '0') - (a[n].second[i] - '0');
            t *= t;
            year += t;
        }

        int month = 0;
        for (int i = 4; i < 6; i++) {
            int t = (s[i] - '0') - (a[n].second[i] - '0');
            t *= t;
            month += t;
        }

        int day = 0;
        for (int i = 6; i < 8; i++) {
            int t = (s[i] - '0') - (a[n].second[i] - '0');
            t *= t;
            day += t;
        }

        a[n].first = year * month * day;
        mx = max(mx, year * month * day);
    }

    vector<int> ans;
    for (auto &p: a) {
        if (p.first == mx)
            ans.push_back(stoi(p.second));
    }

    sort(ans.begin(), ans.end());

    cout << ans[0] << '\n';

    return 0;
}