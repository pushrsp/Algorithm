#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    vector<pair<int, int>> lines(N);
    for (int n = 0; n < N; ++n) {
        cin >> lines[n].first >> lines[n].second;

        if (lines[n].first > lines[n].second) {
            int temp = lines[n].first;
            lines[n].first = lines[n].second;
            lines[n].second = temp;
        }
    }

    sort(lines.begin(), lines.end());

    int result = 0, left = lines[0].first, right = lines[0].second;
    for (int n = 1; n < N; ++n) {
        if (lines[n].first <= right) {
            right = max(right, lines[n].second);
        } else {
            result += right - left;
            left = lines[n].first;
            right = lines[n].second;
        }
    }
    result += right - left;

    cout << result << endl;
    return 0;
}