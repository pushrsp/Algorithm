#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAX 5000001

using namespace std;

int N, L, Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> L;

    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    deque<pair<int, int>> dq;
    for (int i = 1; i <= N; ++i) {
        while (!dq.empty() && dq.front().first < i - L + 1)
            dq.pop_front();

        while (!dq.empty() && dq.back().second > Arr[i])
            dq.pop_back();

        dq.emplace_back(i, Arr[i]);
        cout << dq.front().second << ' ';
    }
    return 0;
}