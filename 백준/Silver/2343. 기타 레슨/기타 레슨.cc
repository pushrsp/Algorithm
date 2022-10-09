#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M, Arr[100001];

bool is_valid(int mid) {
    for (int i = 0; i < N; ++i) {
        if (Arr[i] > mid)
            return false;
    }

    int temp = mid;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (mid - Arr[i] < 0) {
            mid = temp;
            cnt++;
        }

        mid -= Arr[i];
    }

    if (mid != temp)
        cnt++;

    return cnt <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int mx = 0;
    for (int n = 0; n < N; ++n)
        cin >> Arr[n], mx += Arr[n];

    int left = 0, right = mx, ret = INT32_MAX;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_valid(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}