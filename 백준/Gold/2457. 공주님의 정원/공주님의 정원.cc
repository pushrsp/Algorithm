#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<pair<int, int>> vec;
    for (int n = 0; n < N; ++n) {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;

        if (s1 * 100 + s2 < 301) {
            s1 = 3;
            s2 = 1;
        }

        if (e1 * 100 + e2 > 1130) {
            e1 = 12;
            e2 = 01;
        }

        vec.emplace_back(s1 * 100 + s2, e1 * 100 + e2);
    }

    sort(vec.begin(), vec.end());

    int cnt = 0;
    int start = 300;
    int end = 301;
    int maxEnd = 0;
    for (int n = 0; n < N; ++n) {
        if (start < vec[n].first && vec[n].first <= end) {
            if (maxEnd < vec[n].second)
                maxEnd = vec[n].second;

            if (vec[n].second == 1201) {
                cnt++;
                end = maxEnd;
                break;
            }

            continue;
        } else {
            if (end >= maxEnd)
                break;

            cnt++;
            start = end;
            end = maxEnd;
            --n;
        }
    }

    if (end == 1201)
        cout << cnt << endl;
    else
        cout << 0 << endl;

    return 0;
}