#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1500002

using namespace std;

int N, DP[MAX];
pair<int, int> Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> Arr[i].first >> Arr[i].second;

    int ret = 0;
    for (int i = 1; i <= N + 1; ++i) {
        ret = max(ret, DP[i]);
        if (i + Arr[i].first <= N + 1)
            DP[i + Arr[i].first] = max(ret + Arr[i].second, DP[i + Arr[i].first]);
    }

    cout << ret << '\n';

    return 0;
}