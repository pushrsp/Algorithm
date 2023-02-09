#include <iostream>
#include <vector>

#define MAX 300001

using namespace std;

int N, M, Arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int left = 1, right = 0, mid, cap;
    for (int i = 0; i < M; ++i) {
        cin >> Arr[i];
        right = max(right, Arr[i]);
    }

    while (left < right) {
        mid = (left + right) / 2;
        cap = 0;

        for (int i = 0; i < M; ++i) {
            cap += Arr[i] / mid;
            if (Arr[i] % mid)
                cap += 1;
        }

        if (cap > N) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    cout << right << '\n';

    return 0;
}