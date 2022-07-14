#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int arr[1001] = {0,};
int N;

bool cmp_pair(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

int main() {
    cin >> N;

    vector<pair<int, int>> hw;
    for (int n = 0; n < N; ++n) {
        int d, w;
        cin >> d >> w;

        hw.emplace_back(d, w);
    }

    sort(hw.begin(), hw.end(), cmp_pair);

    for (int n = 0; n < N; ++n) {
        for (int i = hw[n].first; i > 0; --i) {
            if (arr[i] == 0) {
                arr[i] = hw[n].second;
                break;
            }
        }
    }

    int sum = 0;
    for (auto &i: arr)
        sum += i;

    cout << sum << endl;
    return 0;
}