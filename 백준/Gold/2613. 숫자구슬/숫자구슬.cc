#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, Arr[301];

void print(int mx) {
    cout << mx << '\n';

    int sum = 0, count = 0;
    for (int i = 0; i < N; ++i) {
        sum += Arr[i];
        if (sum > mx) {
            sum = Arr[i];
            M--;
            cout << count << ' ';
            count = 0;
        }

        count++;

        if (N - i == M)
            break;
    }

    while (M--) {
        cout << count << ' ';
        count = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int left = 0, right = 0, mid, sum, cap, ret;
    for (int n = 0; n < N; ++n) {
        cin >> Arr[n];
        right += Arr[n];
        left = left < Arr[n] ? Arr[n] : left;
    }

    while (left <= right) {
        mid = (left + right) / 2;
        sum = 0, cap = 1;

        for (int i = 0; i < N; ++i) {
            sum += Arr[i];
            if (sum > mid) {
                cap += 1;
                sum = Arr[i];
            }
        }

        if (cap <= M) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    print(ret);

    return 0;
}