#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> lectures;
int days[10001] = {0};

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

int main() {
    cin >> N;

    lectures = vector<pair<int, int>>(N);
    int maxDay = 0;
    for (int n = 0; n < N; ++n) {
        cin >> lectures[n].first >> lectures[n].second;

        if (lectures[n].second > maxDay)
            maxDay = lectures[n].second;
    }

    sort(lectures.begin(), lectures.end(), cmp_pair);

    for (auto &l: lectures) {
        for (int i = l.second; i >= 1; i--) {
            if (days[i] == 0) {
                days[i] = l.first;
                break;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= maxDay; ++i)
        sum += days[i];

    cout << sum << endl;
    return 0;
}