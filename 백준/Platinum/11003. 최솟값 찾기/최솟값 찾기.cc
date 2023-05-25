#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 5000001

using namespace std;

int N, L;
int Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> L;

    for (int i = 1; i <= N; ++i)
        cin >> Arr[i];

    deque<pair<int, int>> dq;
    for (int i = 1; i <= N; ++i) {
        if (!dq.empty() && dq.front().second < i - L + 1)
            dq.pop_front();

        while (!dq.empty() && dq.back().first > Arr[i])
            dq.pop_back();
        dq.emplace_back(Arr[i], i);

        cout << dq.front().first << ' ';
    }
    return 0;
}