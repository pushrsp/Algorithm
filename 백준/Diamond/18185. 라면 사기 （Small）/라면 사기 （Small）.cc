#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, Arr[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int n = 1; n <= N; ++n)
        cin >> Arr[n];

    int ret = 0;
    for (int n = 1; n <= N; ++n) {
        if (Arr[n + 1] > Arr[n + 2]) {
            int mn = min(Arr[n], Arr[n + 1] - Arr[n + 2]);
            ret += 5 * mn;

            Arr[n] -= mn;
            Arr[n + 1] -= mn;

            mn = min(Arr[n], min(Arr[n + 1], Arr[n + 2]));
            ret += 7 * mn;

            Arr[n] -= mn;
            Arr[n + 1] -= mn;
            Arr[n + 2] -= mn;
        } else {
            int mn = min(Arr[n], min(Arr[n + 1], Arr[n + 2]));
            ret += 7 * mn;

            Arr[n] -= mn;
            Arr[n + 1] -= mn;
            Arr[n + 2] -= mn;

            mn = min(Arr[n], Arr[n + 1]);
            ret += 5 * mn;

            Arr[n] -= mn;
            Arr[n + 1] -= mn;
        }

        ret += 3 * Arr[n];
    }

    cout << ret << '\n';

    return 0;
}